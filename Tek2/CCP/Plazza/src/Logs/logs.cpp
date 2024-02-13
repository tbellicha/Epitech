/*
** EPITECH PROJECT, 2022
** Project
** File description:
** logs
*/

#include "logs.hpp"

logs::logs(void)
{
    _file.open(FILEPATH, std::ios::app);
}

logs::~logs(void)
{
}

/**
 * @brief Add a log to the logs file
 *
 * @param log
 */
void logs::addLog(std::string str)
{
    _file << str << std::endl;
}

/**
 * @brief Add a list of logs to the logs file
 *
 */
void logs::addLogs(std::vector<std::string> vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
        addLog(vec[i]);
}

/**
 * @brief Clear the logs file
 *
 */
void logs::clearLogs(void)
{
    std::ofstream clear_file;

    clear_file.open(FILEPATH, std::ofstream::out | std::ofstream::trunc);
    clear_file.close();
}