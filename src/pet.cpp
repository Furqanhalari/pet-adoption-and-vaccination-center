#include <iostream>
#include "../include/pet.h"
using namespace std;

Pet::Pet(int id, string name, string type, int age, string breed, string gender, bool adopted)
:id(id), name(name), type(type), age(age), breed(breed), gender(gender), adopted(adopted) {};

string Pet::getName() const {
    return name;
}

int Pet::getId() const {
    return id;
}

string Pet::getType() const {
    return type;
}

int Pet::getAge() const {
    return age;
}

string Pet::getBreed() const {
    return breed;
}

string Pet::getGender() const {
    return gender;
}

bool Pet::getAdopted() const {
    return adopted;
}

void Pet::displayInfo() const {
    cout << "Pet Id = " << Pet::getId() << endl;
    cout << "Pet Name = " << Pet::getName() << endl;
    cout << "Pet Type = " << Pet::getType() << endl;
    cout << "Pet Age = " << Pet::getAge() << endl;
    cout << "Pet Breed = " << Pet::getBreed() << endl;
    cout << "Pet Gender = " << Pet::getGender() << endl;
    cout << "Pet Adopted = " << Pet::getAdopted() << endl;
}

void Pet::markAdopted() {
    adopted = true;
}

ostream& operator<<(ostream& os, const Pet& pet) {
    os << "Pet ID: " << pet.id << endl;
    os << "Pet Name " << pet.name << endl;
    os << "Pet Type " << pet.type << endl;
    os << "Pet Age " << pet.age << endl;
    os << "Pet Breed " << pet.breed << endl;
    os << "Pet Gender " << pet.gender << endl;
    os << "Pet Adopted " << pet.adopted << endl;
    return os;
}