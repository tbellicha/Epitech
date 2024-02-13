/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
    public:
        IMonitorDisplay();
        ~IMonitorDisplay();
        bool getDisplayCPU() const;
        bool getDisplayInfo() const;
        bool getDisplayRAM() const;
        bool getDisplayNetwork() const;
        bool getDisplayStockage() const;
        void setDisplayCPU(bool status);
        void setDisplayInfo(bool status);
        void setDisplayRAM(bool status);
        void setDisplayNetwork(bool status);
        void setDisplayStockage(bool status);

    protected:
    private:
        bool _displayCPU;
        bool _displayInfo;
        bool _displayRAM;
        bool _displayNetwork;
        bool _displayStockage;
};

#endif /* !IMONITORDISPLAY_HPP_ */
