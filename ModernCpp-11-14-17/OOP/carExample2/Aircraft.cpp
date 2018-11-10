//
// Created by cheetos on 10/11/18.
// DELEGATING CONSTRUCTOR

#include "Aircraft.h"

int Aircraft::totalMachines = 0;

// default
Aircraft::Aircraft(): Aircraft(0, "[Not Assigned]", 0, 0, 0, 0)
{
    std::cout << "DEFAULT AIRCRAFT CREATED" << std::endl;
}

//
// military aircraft
Aircraft::Aircraft(double turbosine, std::string pilot_name)
        : Aircraft(turbosine, pilot_name, 0, 0, 0, 0)
{
    std::cout << "MILITARY AIRCRAFT CREATED" << std::endl;
}

// comercial aircraft
Aircraft::Aircraft(double turbosine, std::string pilot_name, int passagers,
        int flights, double totalKilometers)
        : Aircraft(turbosine, pilot_name, passagers, flights, totalKilometers, 0)
{
    std::cout << "COMERCIAL AIRCRAFT CREATED" << std::endl;
}

// passager aircraft
Aircraft::Aircraft(double turbosine, std::string pilot_name, int passagers,
        int flights, double totalKilometers, int stewardess)
        : turbosine{turbosine}, pilot_name{pilot_name}, passagers{passagers},
        flights{flights}, totalKilometers{totalKilometers}, stewardess{stewardess}
{
    // base constructor
    std::cout << "PASSAGER AIRCRAFT CREATED" << std::endl;
    ++totalKilometers;
}

Aircraft::~Aircraft()
{
    std::cout << "Aircraft data destructed." << std::endl;
}

void Aircraft::fillTurbosine(double amount)
{
    turbosine = amount;
}

void Aircraft::profile() const
{
    std::cout << "Turbosine: " << turbosine << std::endl;
    std::cout << "Passagers: " << passagers << std::endl;
    std::cout << "Stewardess: " << stewardess << std::endl;
    std::cout << "Total Flights: " << flights << std::endl;
    std::cout << "TotalKilometers: " << totalKilometers << std::endl;
    std::cout << "Pilot name: " << pilot_name << std::endl;
}