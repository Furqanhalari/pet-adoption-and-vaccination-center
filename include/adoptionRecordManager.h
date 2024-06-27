#ifndef ADOPTIONRECORDMANAGER_H
#define ADOPTIONRECORDMANAGER_H

#include "adopter.h"
#include "pet.h"
using namespace std;

class AdoptionRecordManager {
public:
    virtual ~AdoptionRecordManager() {};
    virtual void addRecord(int adopterId, int pedId) = 0;
    virtual void loadRecords(const string &fileName) = 0;
    virtual void saveRecords(const string& filename) const = 0;
    virtual void displayRecords() const = 0;
};

#endif