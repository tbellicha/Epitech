/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** fork
*/

#include "fork.hpp"
#include <signal.h>

/**
 * @brief Fork the program and fill _pid with the child pid
 */
void forkPid::forkIt(void)
{
    _pid = fork();
}

/**
 * @brief Get the pid of the child
 *
 * @return int pid of the child
 */
int forkPid::getPid(void)
{
    return _pid;
}

/**
 * @brief kill the pid of the child
 *
 * @param pid
 */
void forkPid::killIt(int pid)
{
    kill(pid, SIGUSR1);
}

/**
 * @brief Send a signal
 *
 * @param void* handler
 */
void forkPid::setSignal(void (*signalHandler)(int))
{
    signal(SIGUSR1, signalHandler);
}

/**
* @brief Wait for a signal
*
* @return int
 */
int forkPid::waitForIt()
{
    return pause();
}
