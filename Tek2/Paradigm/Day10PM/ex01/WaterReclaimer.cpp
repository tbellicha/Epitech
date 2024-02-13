#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer() :
    _water(0),
    _started(false)
{
}

void    WaterReclaimer::start()
{
    if (this->_water == 0)
        throw MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer");
    this->_started = true;
}

void    WaterReclaimer::useWater(int water)
{
    if (this->_water == 0)
        throw UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
    if (water < 0)
        throw UserError("Water use should be positif.", "WaterReclaimer");
    if (this->_water <= 10)
        throw LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    this->_water -= water;
}

void    WaterReclaimer::generateWater()
{
    int nb_water = 10;

    if (this->_water + nb_water > 100)
        throw NasaError("Cannot generate water, reclaimer already full.", "WaterReclaimer");
    this->_water += nb_water;
}
