/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <string>

namespace nts
{
    enum Actions {
        NOTHING,
        EXIT,
        SIMULATE,
        DISPLAY,
        LOOP,
        DUMP
    };

    class NanoTekSpice
    {
    public:
        NanoTekSpice();
        ~NanoTekSpice();
        void exit(void);
        void display(void);
        void setInputValue(void);
        void simulate(void);
        void loop(void);
        void dump(void);
        void run();
        void displayPrompt() const;
        void getAction();
        void AnalyseAction();

    protected:
    private:
        const unsigned short NB_ACTION = 5;
        const char KEYWORD_ACTION[5][10] = {
            {"exit"}, {"simulate"}, {"display"},
            {"loop"}, {"dump"}
        };
        bool _active;
        std::string _line;
        Actions _action;
    };
}

#endif /* !NANOTEKSPICE_HPP_ */
