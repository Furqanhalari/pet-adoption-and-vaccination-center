#include <iostream>
#include "../include/vaccination.h"
using namespace std;

Vaccination::Vaccination(int id, string name, string dateAdministered, int petId)
:id(id), name(name), dateAdministered(dateAdministered), petId(petId) {};

int Vaccination::getId() const {
    return id;
}

string Vaccination::getName() const {
    return name;
}

string Vaccination::getDateAdministered() const {
    return dateAdministered;
}

int Vaccination::getPetId() const {
    return petId;
}

void Vaccination::displayVaccinationInfo() const {
    cout << "Vaccination Id = " << Vaccination::getId() << endl;
    cout << "Vaccination Name = " << Vaccination::getName() << endl;
    cout << "Date Administered = " << Vaccination::getDateAdministered() << endl;
    cout << "Pet Id = " << Vaccination::getPetId() << endl;
}

ostream& operator<<(ostream &os, const Vaccination &vaccination) {
    os << "Vaccination id " << vaccination.id << endl;
    os << "Vaccination name " << vaccination.name << endl;
    os << "Date Administered " << vaccination.dateAdministered << endl;
    os << "Pet Id " << vaccination.petId << endl;
    return os;
}