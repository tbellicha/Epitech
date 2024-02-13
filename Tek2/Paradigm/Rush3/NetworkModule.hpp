/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** NetworkModule
*/

#ifndef NETWORKMODULE_HPP_
#define NETWORKMODULE_HPP_

class NetworkModule {
    public:
        NetworkModule();
        ~NetworkModule();
        void setUp(double);
        void setDown(double);

        double getUp() const;
        double getDown() const;
    private:
        double _up;
        double _down;
};

#endif /* !NETWORKMODULE_HPP_ */
