#pragma once

#include <iostream>
//#include <map>

class Aircraft
{
    private:
        static int totalMachines;
        double turbosine;
        int passagers;
        int stewardess;
        int flights;
        double totalKilometers;
        std::string pilot_name;
        //std::string lastFlight;
        //std::string newFlight;
        //std::map<long int,std::string> *flightsRecord;

    public:
        // initializing new airplane
        Aircraft();
        // initializing military airplane
        Aircraft(double turbosine, std::string pilot_name);
        // initializing comercial airplane
        Aircraft(double turbosine, std::string pilot_name, int passagers,
                int flights, double totalKilometers);
        // Passagers aircraft
        Aircraft(double turbosine, std::string pilot_name, int passagers,
                int flights, double totalKilometers, int stewardess);

        ~Aircraft(); // Destructor

        void fillTurbosine(double amount);
        void profile() const;

};