/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** fork
*/

#ifndef FORK_HPP_
#define FORK_HPP_

#include <unistd.h>

class forkPid {
  public:
    void forkIt();
    int getPid();
    void killIt(int pid);
    void setSignal(void (*signalHandler)(int));
    int waitForIt();

  protected:
    int _pid;
};

#endif /* !FORK_HPP_ */
