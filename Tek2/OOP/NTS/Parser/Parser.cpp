/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

nts::Parser::Parser(const std::string& filename)
{
    int i = 0;
    std::string content_no_comments;
    std::ifstream myFile;
    std::stringstream ss;

    myFile.open(filename);
    if (myFile.fail())
        throw nts::FileException("Invalid file: " + filename);
    this->_filename = filename;
    ss << myFile.rdbuf();
    this->_file_content = ss.str();
    myFile.close();
    if (this->_file_content.find(".chipsets:") >= this->_file_content.length())
        throw nts::FileException("Statement \".chipsets:\" missing.");
    if (this->_file_content.find(".links:") >= this->_file_content.length())
        throw nts::FileException("Statement \".links:\" missing.");
    while (this->_file_content[i]) {
        if (this->_file_content[i] == '#') {
            if (i > 0 && this->_file_content[i - 1] != '\n')
                content_no_comments += '\n';
            while (this->_file_content[i] && this->_file_content[i] != '\n')
                i++;
            i++;
        } else {
            content_no_comments += this->_file_content[i];
            i++;
        }
    }
    this->_file_content = content_no_comments;
}

nts::Parser::~Parser()
{
}

void nts::Parser::ComputeParsing()
{
    std::stringstream ss(this->_file_content);
    std::string line;
    std::string component;
    std::string name;
    std::string name2;
    std::string pin;
    std::string pin2;
    nts::Factory fact;
    int i = 0;

    while (getline(ss, line, '\n')) {
        component = "";
        name = "";
        pin = "";
        if (line == ".chipsets:") {
            this->_if_chipset = true;
            this->_if_links = false;
            continue;
        } else if (line == ".links:") {
            if (this->_compo.empty() && this->_if_chipset == true)
                throw nts::ChipsetException("No chispet in the circuit");
            this->_if_links = true;
            this->_if_chipset = false;
            continue;
        } else if (line == "\0") {
            if (this->_compo.empty() && this->_if_chipset == true)
                throw nts::ChipsetException("No chispet in the circuit");
            this->_if_chipset = false;
            this->_if_links = false;
        }
        if (this->_if_chipset) {
            (std::stringstream) line >> component;
            (std::stringstream) &line[component.length()] >> name;
            if (name == "\0")
                throw nts::ComponentNameException("Invalid name for component");
            if (CheckName(name))
                throw nts::ComponentNameException("Several components share the same name : " + name);
            this->_compo[name] = fact.createComponent(component);
        } else if (this->_if_links) {
            (std::stringstream) line >> name;
            i = name.find(":");
            if (i >= (int) name.length() - 1)
                throw nts::PinException("Missing pin value");
            pin = name.substr(i + 1, name.length());
            if (!isPosNumber(pin))
                throw nts::PinException("Usage of invalid pin : " + pin);
            name = name.substr(0, name.find(":"));
            if (!this->CheckName(name))
                throw nts::ComponentNameException("Usage of unknown component : " + name);
            (std::stringstream) &line[name.length() + pin.length() + 1] >> name2;
            i = name2.find(":");
            if (i >= (int) name2.length() - 1)
                throw nts::PinException("Missing pin2 value");
            pin2 = name2.substr(i + 1, name2.length());
            if (!isPosNumber(pin2))
                throw nts::PinException("Usage of invalid pin2 : " + pin2);
            name2 = name2.substr(0, name2.find(":"));
            if (!this->CheckName(name2))
                throw nts::ComponentNameException("Usage of unknown component : " + name2);
        }
    }
}

bool nts::Parser::isPosNumber(std::string str)
{
    for (int i = 0; i < (int) str.length(); i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (false);
    return (true);
}

bool nts::Parser::CheckName(std::string name)
{
    if (this->_compo.count(name))
        return (true);
    return (false);
}