#include <iostream>
#include <vector>
#include <algorithm>

#include "../include/adopter.h"
#include "adopter.cpp"
#include "../include/adopterCenter.h"
#include "../include/pet.h"
#include "pet.cpp"
#include "../include/vaccination.h"
#include "termsAndConditions.cpp"
#include "../include/fileManager.h"
#include "fileManager.cpp"
using namespace std;

AdoptionCenter::AdoptionCenter() {}; 

AdoptionCenter::AdoptionCenter(vector<Pet> pets, vector<Adopter> adopters, vector<Vaccination> vaccinations)
:pets(pets), adopters(adopters), vaccinations(vaccinations) {};

void AdoptionCenter::addPet(const Pet &pet) {
    pets.push_back(pet);
}

void AdoptionCenter::addAdopter(const Adopter &adopter) {
    adopters.push_back(adopter);
}

void AdoptionCenter::addVaccination(const Vaccination &vaccination) {
    vaccinations.push_back(vaccination);
}

void AdoptionCenter::adoptPet(int petId, int adopterId) {
    //first agree to terms and conditions
    //handle payment
    cout << AdoptionCenter::findAdopterById(adopterId)->getName() << " adopted the pet with " << AdoptionCenter::findPetById(petId)->getName() << endl;
}

Pet* AdoptionCenter::findPetById(int petId) {
    auto it = find_if(pets.begin(), pets.end(), [petId](const Pet& pet) {
        return pet.getId() == petId;
    });

    if (it != pets.end()) {
        cout << petId << " found! Name: " << it->getName() << endl;
        return &(*it);
    } else {
        cout << petId << " not found!" << endl;
        return nullptr;
    }
}

Adopter* AdoptionCenter::findAdopterById(int adopterId) {
    auto it = find_if(adopters.begin(), adopters.end(), [adopterId](const Adopter& adopter) {
        return adopter.getId() == adopterId;
    });

    if (it != adopters.end()) {
        cout << adopterId << " found! Name: " << it->getName() << endl;
        return &(*it);
    } else {
        cout << adopterId << " not found!" << endl;
        return nullptr;
    }
}

void AdoptionCenter::displayAllPets() {
    setConsoleTextColor(ConsoleColor::LightBlue);
    for (int i = 0; i < pets.size(); i++) {
        cout << pets[i] << endl;
    }
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void AdoptionCenter::displayAllAdopters() {
    setConsoleTextColor(ConsoleColor::LightGreen);
    for (int i = 0; i < adopters.size(); i++) {
        cout << adopters[i] << endl;
    }
    setConsoleTextColor(ConsoleColor::BrightWhite);

}

void AdoptionCenter::displayAllVaccination() {
    setConsoleTextColor(ConsoleColor::LightYellow);
    for (int i = 0; i < vaccinations.size(); i++) {
        cout << vaccinations[i] << endl;
    }
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

vector<Pet> AdoptionCenter::getPets() const {
    return pets;
}

void AdoptionCenter::setPets(const vector<Pet> &pets) {
    this->pets = pets;
}

vector<Adopter> AdoptionCenter::getAdopters() const {
    return adopters;
}

void AdoptionCenter::setAdopters(const vector<Adopter> &adopters) {
    this->adopters = adopters;
}

vector<Vaccination> AdoptionCenter::getVaccinations() const {
    return vaccinations;
}

void AdoptionCenter::setVaccinations(const vector<Vaccination> &vaccinations) {
    this->vaccinations = vaccinations;
}
