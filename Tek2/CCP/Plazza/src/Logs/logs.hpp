/*
** EPITECH PROJECT, 2022
** Project
** File description:
** logs
*/

#ifndef LOGS_HPP_
#define LOGS_HPP_

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

#define FILEPATH "logs.txt"

class logs {
  public:
    logs();
    ~logs();

    void addLog(std::string str);
    void addLogs(std::vector<std::string> vec);
    void clearLogs(void);

  private:
    std::ofstream _file;
};
#endif /* !LOGS_HPP_ */
