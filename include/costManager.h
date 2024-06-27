#ifndef COSTMANAGER_H
#define COSTMANAGER_H

#include <iostream>
using namespace std;

class CostManager {
private:
    static constexpr double default_adoption_fees = 50.0;
    static constexpr double default_vaccination_fees = 20.0;
public:
    static double getAdoptionFees(string petType);
    static double getVaccinationFees(string vaccinationType);
};

#endif