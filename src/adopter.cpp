#include <iostream>
#include <vector>

#include "../include/adopter.h"
using namespace std;

Adopter::Adopter(int id, string name, string address, string phoneNumber)
:id(id), name(name), address(address), phoneNumber(phoneNumber) {};

int Adopter::getId() const {
    return id;
}

string Adopter::getName() const {
    return name;
}

string Adopter::getAddress() const {
    return address;
}

string Adopter::getPhoneNumber() const {
    return phoneNumber;
}

vector<int> Adopter::getAdopterPetIds() const {
    return adoptedPetIds;
}

void Adopter::addAdoptedPet(int petId) {
    adoptedPetIds.push_back(petId);
}
