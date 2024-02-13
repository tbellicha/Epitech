/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <iostream>
#include <mqueue.h>
#include <sys/ipc.h>
#include <sys/types.h>

class message {
  public:
    message();
    ~message();
    void unlinkClose();
    message &operator>>(std::string &str);
    message &operator<<(std::string str);

  private:
    mqd_t _qd;
};

#endif /* !MESSAGE_HPP_ */
