#!/usr/bin/env python3.10
import sys
import os
import time
import copy

class Task:
    def __init__(self, code, name, duration, previous_tasks):
        self.code = code
        self.name = name
        self.duration = duration
        self.previous_tasks = previous_tasks
        self.order = 0
    def __str__(self):
        return f"{self.code} {self.name} {self.duration} {self.previous_tasks}"


def read_and_compute_file(f):
    tasks_list = []
    for line in f:
        line = line.strip()
        if line.count(';') < 2:
            print("Invalid line: '" + line + "'", file=sys.stderr)
            sys.exit(84)
        code = line.split(';')[0]
        name = line.split(';')[1]
        duration = line.split(';')[2]
        previous_tasks = []
        for i in range(3, line.count(';') + 1):
            previous_tasks.append(line.split(';')[i])
        myTask = Task(code, name, duration, previous_tasks)
        tasks_list.append(myTask)
    found_first = False
    for task in tasks_list:
        ## Check if there is multiple tasks with no previous tasks
        if task.previous_tasks == []:
            if found_first:
                print("Invalid file: multiple first tasks", file=sys.stderr)
                sys.exit(84)
            found_first = True
            break
        ## Check if there is a task with a previous task that doesn't exist
        for prev in task.previous_tasks:
            if prev not in [task.code for task in tasks_list]:
                print("Invalid file: unknown task", file=sys.stderr)
                sys.exit(84)
        ## Check if there is a task with invalid duration (negative or not a number)
        if not duration.isdigit() or int(duration) < 0:
            print("Invalid file: invalid duration", file=sys.stderr)
            sys.exit(84)
    if not found_first:
        print("Invalid file: no first task", file=sys.stderr)
        sys.exit(84)
    return tasks_list


def get_each_days(tl):
    list_days = []
    to_remove = []
    pre_tasks = []
    day = 0
    tasks_list = copy.deepcopy(tl)
    while tasks_list:
        check_cycle = True
        for task in tasks_list:
            if task.previous_tasks == []:
                if int(task.duration) == 0:
                    pre_tasks.append(task.code)
                    tasks_list.remove(task)
                    to_remove.append(task.code)
                    check_cycle = False
        if check_cycle:
            break
        for task2 in tasks_list:
            for prev in to_remove:
                if prev in task2.previous_tasks:
                    task2.previous_tasks.remove(prev)
    while tasks_list:
        check_cycle = True
        for task in tasks_list:
            if task.previous_tasks == []:
                if len(list_days) <= day:
                    list_days.append([task.code])
                else:
                    list_days[day].append(task.code)
                task.duration = int(task.duration) - 1
                if task.duration == 0:
                    tasks_list.remove(task)
                    to_remove.append(task.code)
                check_cycle = False
        if check_cycle:
            print("Invalid file: cyclic dependencies", file=sys.stderr)
            sys.exit(84)
        for task2 in tasks_list:
            for prev in to_remove:
                if prev in task2.previous_tasks:
                    task2.previous_tasks.remove(prev)
        day += 1
    return pre_tasks, list_days


def sort_tab(name_tab, duration_tab, starting_tab):
    for i in range(len(name_tab)):
        for k in range(len(name_tab)):
            if int(duration_tab[i]) == 0 or int(duration_tab[k]) == 0:
                break
            if starting_tab[i] == starting_tab[k] and int(duration_tab[i]) > int(duration_tab[k]):
                name_tab[i], name_tab[k] = name_tab[k], name_tab[i]
                duration_tab[i], duration_tab[k] = duration_tab[k], duration_tab[i]
                starting_tab[i], starting_tab[k] = starting_tab[k], starting_tab[i]
                return name_tab, duration_tab, starting_tab
    return name_tab, duration_tab, starting_tab


def process(argc, argv):
    try:
        f = open(argv[1])
    except FileNotFoundError:
        print("File doesn't exists", file=sys.stderr)
        return 84
    if os.path.getsize(argv[1]) == 0:
        print("File is empty", file=sys.stderr)
        return 84
    tasks_list = read_and_compute_file(f)
    pre_tasks, list_days = get_each_days(tasks_list)
    name_tab = []
    duration_tab = []
    starting_tab = []
    for i in range(len(pre_tasks)):
        name_tab.append(pre_tasks[i])
        duration_tab.append(0)
        starting_tab.append(0)
    for i in range(len(list_days)):
        for task in list_days[i]:
            if task not in name_tab:
                name_tab.append(task)
                duration_tab.append(tasks_list[[task.code for task in tasks_list].index(task)].duration)
                starting_tab.append(i)
    name_tab, duration_tab, starting_tab = sort_tab(name_tab, duration_tab, starting_tab)
    last_task = len(name_tab) - 1
    print(f'Total duration of construction: {starting_tab[last_task] + int(duration_tab[last_task])} weeks\n')
    for i in range(len(name_tab)):
        if i == 0:
            print(f'{name_tab[i]} must begin at t={starting_tab[i]}')
            continue
        if starting_tab[i] != starting_tab[i - 1] or duration_tab[i - 1] == 0:
            print(f'{name_tab[i]} must begin at t={starting_tab[i]}')
        elif starting_tab[i] == starting_tab[i - 1]:
            print(f'{name_tab[i]} must begin between t={starting_tab[i]} and t={starting_tab[i] + int(duration_tab[i + 1]) - (starting_tab[i] - (starting_tab[i + 1] - int(duration_tab[i])))}')
    print('')
    for i in range(len(name_tab)):
        x = 0
        if i > 1 and starting_tab[i] == starting_tab[i - 1] and int(duration_tab[i - 1]) != 0:
            x = int(duration_tab[i + 1]) - (starting_tab[i] - (starting_tab[i + 1] - int(duration_tab[i])))
        print(f'{name_tab[i]}\t({x})\t{" " * int(starting_tab[i])}{"=" * int(duration_tab[i])}')
    f.close()
