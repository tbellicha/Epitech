/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** thread
*/

#include "thread.hpp"

/**
 * @brief Creates a new thread with func as the function and arg as the arg
 *
 * @param thread
 * @param func
 * @param arg
 */
void threadEncapsulation::thread_create(pthread_t *thread, void *(*func)(void *), void *arg)
{
    pthread_create(thread, NULL, func, arg);
}

/**
 * @brief Destroys the thread
 *
 */
void threadEncapsulation::thread_cancel(pthread_t thread)
{
    pthread_cancel(thread);
}
