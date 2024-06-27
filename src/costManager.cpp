#include <iostream>

#include "../include/costManager.h"
using namespace std;

double CostManager::getAdoptionFees(string petType) {
    if (petType == "cat" || petType == "Cat") {
        return default_adoption_fees + 20;
    }
    else if (petType == "dog" || petType == "Dog") {
        return default_adoption_fees + 30;
    }
    else if (petType == "rabbit" || petType == "Rabbit") {
        return default_adoption_fees + 50;
    }
    else if (petType == "bird" || petType == "Bird") {
        return default_adoption_fees;
    }
    else {
        cout << "Pet is not available" << endl;
    }
}

double CostManager::getVaccinationFees(string vaccinationType) {
    if (vaccinationType == "rabies" || vaccinationType == "Rabies") {
        return default_vaccination_fees;
    }
    else if (vaccinationType == "distemper" || vaccinationType == "Distemper") {
        return default_vaccination_fees + 20;
    }
    else if (vaccinationType == "parvovirus" || vaccinationType == "Parvovirus") {
        return default_vaccination_fees + 30;
    }
    else if (vaccinationType == "hepatitis" || vaccinationType == "Hepatitis") {
        return default_vaccination_fees + 40;
    }
    else if (vaccinationType == "bordetella" || vaccinationType == "Bordetella") {
        return default_vaccination_fees + 50;
    }
    else {
        cout << "Vaccination is not available" << endl;
    }
}