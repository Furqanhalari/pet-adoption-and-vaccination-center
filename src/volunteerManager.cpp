#include "../include/volunteerManager.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class VolunteerManagerChild: public VolunteerManager {
private:
    vector<pair<string, string>> volunteers;
public:
    void addVolunteer(const string& name, const string& contact) {
        volunteers.push_back({name, contact});
    }

    void loadVolunteers(const string& filename) {
        volunteers.clear();
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for reading: " << filename << endl;
            return;
        }

        string name, contact;
        while (inFile >> name >> contact) {
            volunteers.push_back({name, contact});
        }
        inFile.close();
    }

    void saveVolunteers(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file for writing: " << filename << endl;
            return;
        }

        for (const auto& volunteer : volunteers) {
            outFile << volunteer.first << " " << volunteer.second << endl;
        }
        outFile.close();
    }

    void displayVolunteers() const {
        for (const auto& volunteer : volunteers) {
            cout << "Volunteer Name: " << volunteer.first << ", Contact: " << volunteer.second << endl;
        }
    }
};