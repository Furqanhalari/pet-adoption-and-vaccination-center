#ifndef VACCINATION_H
#define VACCINATION_H

#include <iostream>
using namespace std;

class Vaccination {
private:
    int id;
    string name;
    string dateAdministered;
    int petId;
public:
    Vaccination(int id, string name, string dateAdministered, int petId);
    int getId() const;
    string getName() const;
    string getDateAdministered() const;
    int getPetId() const;
    void displayVaccinationInfo() const;
    friend ostream& operator<<(ostream &os, const Vaccination &vaccination);
};

#endif