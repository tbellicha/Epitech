/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-tanguy.bellicha
** File description:
** display
*/

#include "my.h"

char **fill_file_infos(struct stat stat_s, struct dirent *dirent_s)
{
    struct group *group_s;
    struct passwd *passwd_s;
    char **line = malloc(sizeof(char **) * 4096);
    int i_str = 0;

    group_s = getgrgid(stat_s.st_gid);
    passwd_s = getpwuid(stat_s.st_uid);
    line[i_str++] = get_perms(stat_s);
    line[i_str++] = int_to_str(stat_s.st_nlink);
    line[i_str++] = passwd_s->pw_name;
    line[i_str++] = group_s->gr_name;
    line[i_str++] = int_to_str(stat_s.st_size);
    line[i_str++] = get_time(ctime(&stat_s.st_mtime));
    line[i_str++] = dirent_s->d_name;
    line[i_str++] = int_to_str(stat_s.st_blocks/2);
    return (line);
}

char **is_need_swap(char ***ls, char **tab, int i, int k)
{
    char ***tempo_triple = ls;
    char **line_tempo = malloc(sizeof(char **));

    if (tab[i] == ls[k][6]) {
        line_tempo = tempo_triple[i];
        tempo_triple[i] = ls[k];
        ls[k] = line_tempo;
    }
    return (line_tempo);
}

void print_triple_star(char ***line, int nb_line, int nb_elements)
{
    int i = 0;

    while (i < nb_line) {
        my_put_tab(line[i], " ", nb_elements);
        i++;
    }
}

void display_result(char *dirpath, s_my_ls params) {
    DIR *dir = opendir(dirpath);
    struct dirent *dirent_s;
    struct stat stat_s;
    char *filepath = malloc(sizeof(char) * 256);
    char ***all_lines;
    int i_line = 0;
    char **line = malloc(sizeof(char) * 24);

    all_lines = malloc(sizeof(char ***));
    if (params.lsl) {
        if (dirpath[my_strlen(dirpath) - 1] != '/')
            my_strcat(dirpath, "/");
        dir = opendir(dirpath);
        if (lstat(dirpath, &stat_s))
            exit(84);
        while ((dirent_s = readdir(dir))) {
            if (dirent_s->d_name[0] != '.') {
                my_strcpy(filepath, dirpath);
                my_strcat(filepath, dirent_s->d_name);
                lstat(filepath, &stat_s);
                line = fill_file_infos(stat_s, dirent_s);
                all_lines[i_line++] = line;
            }
            my_printf("Hey");
        }
        my_printf("efdds");
        my_printf("total %d\n", my_get_total_blocks(all_lines, i_line));
        all_lines = sort_alphabetically_triple(all_lines, i_line, 1);
        params.lsl = 0;
    }
}