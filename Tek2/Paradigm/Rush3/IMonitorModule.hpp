/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGRUSH3-johan.chrillesen
** File description:
** IMonitorModule
*/

#ifndef IMonitorModule_HPP_
#define IMonitorModule_HPP_

#include <string>

class IMonitorModule {
    public:
        IMonitorModule();
        virtual ~IMonitorModule();

        std::string getTitle() const;
        void setTitle(std::string title);

    protected:
        std::string title;

    private:
};

#endif /* !IMonitorModule_HPP_ */
