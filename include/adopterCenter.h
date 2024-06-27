#ifndef ADOPTERCENTER_H
#define ADOPTERCENTER_H

#include <iostream>
#include <vector>
#include "pet.h"
#include "adopter.h"
#include "vaccination.h"
using namespace std;

class AdoptionCenter {
private:
    vector<Pet> pets;
    vector<Adopter> adopters;
    vector<Vaccination> vaccinations;
public:
    AdoptionCenter();
    AdoptionCenter(vector<Pet> pets, vector<Adopter> adopters, vector<Vaccination> vaccinations);
    void addPet(const Pet &pet);
    void addAdopter(const Adopter &adopter);
    void addVaccination(const Vaccination &vaccination);
    void adoptPet(int petId, int adopterId);
    Pet* findPetById(int petId);
    Adopter* findAdopterById(int adopterId);
    void displayAllPets();
    void displayAllAdopters();
    void displayAllVaccination();
    vector<Pet> getPets() const;
    void setPets(const vector<Pet> &pets);
    vector<Adopter> getAdopters() const;
    void setAdopters(const vector<Adopter> &adopters);
    vector<Vaccination> getVaccinations() const;
    void setVaccinations(const vector<Vaccination> &vaccinations);
};

#endif