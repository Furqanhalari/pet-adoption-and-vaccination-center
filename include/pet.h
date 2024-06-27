#ifndef PET_H
#define PET_H

#include <iostream>
using namespace std;

class Pet {
private:
    int id;
    string name;
    string type;
    int age;
    string breed;
    string gender;
    bool adopted;
public:
    Pet(int id, string name, string type, int age, string breed, string gender, bool adopted);
    int getId() const;
    string getName() const;
    string getType() const;
    int getAge() const;
    string getBreed() const;
    string getGender() const;
    bool getAdopted() const;
    void displayInfo() const;
    void markAdopted();
    friend ostream& operator<<(ostream& os, const Pet& pet);
};

#endif