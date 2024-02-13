/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "NanoTekSpice.hpp"
#include <iostream>
#include <csignal>

static volatile bool keepRunning = false;

nts::NanoTekSpice::NanoTekSpice()
{
    this->_active = true;
}

nts::NanoTekSpice::~NanoTekSpice()
{
}

void nts::NanoTekSpice::exit(void)
{
    this->_active = false;
}

void nts::NanoTekSpice::display(void)
{
    std::cout << "display" << std::endl;
}

void nts::NanoTekSpice::setInputValue(void)
{
}

void nts::NanoTekSpice::simulate(void)
{
    std::cout << "simulate" << std::endl;
}

void signalHandler(int signum)
{
    // std::cout << "Interrupt signal (" << signum << ") received.\n";
    if (keepRunning)
        keepRunning = false;
    else
        exit(signum);
}

void nts::NanoTekSpice::loop(void)
{
    signal(SIGINT, signalHandler);
    while (keepRunning)
    {
        simulate();
        display();
    }
}

void nts::NanoTekSpice::dump(void)
{
    std::cout << "dump" << std::endl;
}

void nts::NanoTekSpice::displayPrompt() const
{
    std::cout << "> ";
}

void nts::NanoTekSpice::run()
{
    NanoTekSpice::displayPrompt();
    while (_active && std::getline(std::cin, _line))
    {
        getAction();
        AnalyseAction();
        if (_action == EXIT)
            return;
        NanoTekSpice::displayPrompt();
    }
}

void nts::NanoTekSpice::getAction()
{
    _action = NOTHING;
    if (_line.size() == 0)
        return;
    for (int i = 0; i < NB_ACTION; i++)
        if (_line.compare(KEYWORD_ACTION[i]) == 0)
        {
            switch (i)
            {
            case 0:
                _action = EXIT;
                break;
            case 1:
                _action = SIMULATE;
                break;
            case 2:
                _action = DISPLAY;
                break;
            case 3:
                _action = LOOP;
                break;
            case 4:
                _action = DUMP;
                break;
            default:
                _action = NOTHING;
                break;
            }
        }
}

void nts::NanoTekSpice::AnalyseAction()
{
    if (_action == DUMP)
        dump();
    if (_action == SIMULATE)
        simulate();
    if (_action == DISPLAY)
        display();
    if (_action == LOOP) {
        keepRunning = true;
        loop();
    }
}
