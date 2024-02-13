/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "IComponent.hpp"
#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <unordered_map>

namespace nts
{
    class Parser
    {

    public:
        Parser(const std::string &filename);
        ~Parser();
        void ComputeParsing();
        bool CheckName(std::string name);
        bool isPosNumber(std::string name);

    protected:
    private:
        std::string _filename;
        std::string _file_content;
        bool _if_chipset;
        bool _if_links;
        // std::vector<std::unique_ptr<nts::IComponent>> _components;
        // std::vector<std::string> _names;
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _compo;
    };
}

#endif /* !PARSER_HPP_ */
