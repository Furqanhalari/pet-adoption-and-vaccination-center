#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/fileManager.h"
using namespace std;

void FileManager::savePets(const vector<Pet> &pets) {
    ofstream fout;
    fout.open("data/pets.txt");
    for (const auto& pet: pets) {
        fout << pet.getId() << "," 
                << pet.getName() << "," 
                << pet.getType() << "," 
                << pet.getAge() << "," 
                << pet.getBreed() << "," 
                << pet.getGender() << "," 
                << pet.getAdopted() << "\n";
    }
    fout.close();
}

vector<Pet> FileManager::loadPets() {
    vector<Pet> pets;
    ifstream fin;
    fin.open("data/pets.txt");
    string line;

    while(getline(fin, line)) {
        stringstream ss(line);
        string item;
        vector<string> items;

        while(getline(ss, item, ',')) {
            items.push_back(item);
        }

        if (items.size() == 7) {
            Pet pet(stoi(items[0]), items[1], items[2], stoi(items[3]), items[4], items[5], items[6] == "1");
            pets.push_back(pet);
        }
    }
    fin.close();
    return pets;
}

void FileManager::saveAdopters(const vector<Adopter> &adopters) {
    ofstream fout;
    fout.open("data/adopters.txt");
    for (const auto& adopter : adopters) {
        fout << adopter.getId() << ','
             << adopter.getName() << ','
             << adopter.getAddress() << ','
             << adopter.getPhoneNumber() << endl;
    }
    fout.close();
}

vector<Adopter> FileManager::loadAdopters() {
    vector<Adopter> adopters;
    ifstream fin;
    fin.open("data/adopters.txt");
    string line;

    while(getline(fin, line)) {
        stringstream ss(line);
        string item;
        vector<string> items;

        while(getline(ss, item, ',')) {
            items.push_back(item);
        }

        if(items.size() == 4) {
            Adopter adopter(stoi(items[0]), items[1], items[2], items[3]);
            adopters.push_back(adopter);
        }
    }

    fin.close();
    return adopters;
}

void FileManager::saveVaccinations(const vector<Vaccination>& vaccinations) {
    ofstream outFile("data/vaccinations.txt");
    for (const auto& vaccination : vaccinations) {
        outFile << vaccination.getId() << "," 
                << vaccination.getName() << "," 
                << vaccination.getDateAdministered() << "," 
                << vaccination.getPetId() << "\n";
    }
    outFile.close();
}

vector<Vaccination> FileManager::loadVaccinations() {
    vector<Vaccination> vaccinations;
    ifstream inFile("data/vaccinations.txt");
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string item;
        vector<string> items;

        while (getline(ss, item, ',')) {
            items.push_back(item);
        }

        if (items.size() == 4) {
            Vaccination vaccination(stoi(items[0]), items[1], items[2], stoi(items[3]));
            vaccinations.push_back(vaccination);
        }
    }
    inFile.close();
    return vaccinations;
}