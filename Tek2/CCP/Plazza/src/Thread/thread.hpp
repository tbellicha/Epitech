/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_
#include <pthread.h>

class threadEncapsulation
{
public:
    static void thread_create(pthread_t *, void *(*)(void *), void *);
    static void thread_cancel(pthread_t);
};

#endif /* !THREAD_HPP_ */
