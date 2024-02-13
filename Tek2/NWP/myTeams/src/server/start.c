/*
** EPITECH PROJECT, 2022
** MyTeams
** File description:
** Server running
*/

#include "server.h"

#include <signal.h>

void server_start(server_t *server)
{
    sigset_t sigint_mask;
    sigset_t old_mask;
    sigset_t pending_signals;
    int recieved_signal;

    sigemptyset(&sigint_mask);
    sigaddset(&sigint_mask, SIGINT);
    sigaddset(&sigint_mask, SIGPIPE);
    sigprocmask(SIG_BLOCK, &sigint_mask, &old_mask);
    for (;;) {
        sigpending(&pending_signals);
        if (sigismember(&pending_signals, SIGINT)) {
            sigwait(&sigint_mask, &recieved_signal);
            break;
        } else
            server_cycle(server);
    }
    sigprocmask(SIG_SETMASK, &old_mask, NULL);
}
