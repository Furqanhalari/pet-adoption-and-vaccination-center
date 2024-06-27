#ifndef ADOPTER_H
#define ADOPTER_H

#include <iostream>
#include <vector>
using namespace std;

class Adopter {
private:
    int id;
    string name;
    string address;
    string phoneNumber;
    vector<int> adoptedPetIds;
public:
    Adopter(int id, string name, string address, string phoneNumber);
    int getId() const;
    string getName() const;
    string getAddress() const;
    string getPhoneNumber() const;
    vector<int> getAdopterPetIds() const;
    void addAdoptedPet(int id);
    friend ostream& operator<< (ostream &os, const Adopter &adopter) {
        os << "Adopter id " << adopter.id << endl;
        os << "Adopter name " << adopter.name << endl;
        os << "Adopter address " << adopter.address << endl;
        os << "Adopter phone number " << adopter.phoneNumber << endl;
    }
};

#endif