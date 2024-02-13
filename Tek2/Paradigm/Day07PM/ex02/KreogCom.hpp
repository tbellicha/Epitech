/*
** EPITECH PROJECT, 2022
** B-PDG-300-NAN-3-1-PDGD07pm-tanguy.bellicha
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom() const;
        void ping();
        void locateSquad();

    private :
        const int _m_serial;
        int _x;
        int _y;
        KreogCom *_next;
};

#endif /* !KREOGCOM_HPP_ */
