#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "pet.h"
#include "adopter.h"
#include "vaccination.h"

class FileManager {
public:
    static void savePets(const vector<Pet> &pets);
    static vector<Pet> loadPets();
    static void saveAdopters(const vector<Adopter> &adopters);
    static vector<Adopter> loadAdopters();
    static void saveVaccinations(const vector<Vaccination> &vaccinations);
    static vector<Vaccination> loadVaccinations();
};

#endif