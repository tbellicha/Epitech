/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD12-tanguy.bellicha
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <string>

class Stack
{
    public:
        class Error : public std::exception
        {
            public:
                Error(std::string message) : _message(message) {}
                const char *what() const throw() { return _message.c_str(); }

            private:
                std::string _message;
        };
        Stack();
        ~Stack();

        void push(double value);
        double pop();
        double top() const;
        void add();
        void sub();
        void mul();
        void div();

        std::stack<double> stck;

    protected:
    private:
};


#endif /* !STACK_HPP_ */
