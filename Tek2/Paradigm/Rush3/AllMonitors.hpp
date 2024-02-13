/*
** EPITECH PROJECT, 2022
** RUSH3
** File description:
** AllMonitors
*/

#ifndef AllMonitors_HPP_
#define AllMonitors_HPP_

#include <string>
#include "IMonitorModule.hpp"
#include "NetworkModule.hpp"
#include "CoreInfo.hpp"

class AllMonitors : public IMonitorModule {
    public:
        AllMonitors();
        virtual ~AllMonitors();

        size_t getNbCore() const;
        double getPercentageUse() const;
        double getTemperature() const;
        const CoreInfo* getCoreInfo() const;
        void getCorePercentInfo();
        void initRam();
        void initNetwork();
        void initDiskSpace();
        NetworkModule getNetwork() const;
        double getRamUsed() const;
        double getRamTotal() const;
        double getDiskFree() const;
        double getDiskAvail() const;

        void setAllInfo();
        void printAllInfo();

    protected:
    private:
        NetworkModule _network;
        size_t _nbCore;
        CoreInfo *_coreInfo;
        double _allCoreUsage;
        double _ramUsed;
        double _ramTotal;
        double _memoFree;
        double _memoAvail;
};

#endif /* !AllMonitors_HPP_ */
