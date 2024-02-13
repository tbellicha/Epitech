/*
** EPITECH PROJECT, 2022
** B-CCP-400-NAN-4-1-theplazza-tanguy.bellicha
** File description:
** message
*/

#include "message.hpp"

/**
*@brief Construct a new message::message object
*
**/
message::message()
{
    mqd_t qd;

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    if ((qd = mq_open("/plazza", O_RDWR | O_CREAT, 0660, &attr)) == -1) {
        perror("Plazza: mq_open");
        exit(84);
    }
    _qd = qd;
}

/**
*@brief Destroy the message::message object
*
**/
message::~message()
{
}

void message::unlinkClose()
{
    mq_unlink("/plazza");
}

/**
 *@brief Sends message to the queue
 *
 *@param str string to be sent
 **/
message &message::operator<<(std::string str)
{
    if ((mq_send(_qd, str.c_str(), str.length() + 1, 0)) == -1) {
        perror("Client: mq_send");
        exit(1);
    }
    return *this;
}

/**
 *@brief Gets the first message in the queue
 *
 *@param str reference to the string to fill
 **/
message &message::operator>>(std::string &str)
{
    char buf[256];

    if (mq_receive(_qd, buf, 256, NULL) == -1) {
        perror("Receive: mq_receive");
        exit(1);
    }
    str = buf;
    return *this;
}
