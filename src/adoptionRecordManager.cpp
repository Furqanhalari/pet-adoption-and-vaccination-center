#include "../include/adoptionRecordManager.h"
#include "../include/consoleUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class AdoptionRecordManagerChild: public AdoptionRecordManager {
private:
    vector<pair<int, int>> records;
public:
    void addRecord(int adopterId, int pedId) {
        records.push_back({adopterId, pedId});
    }

    void loadRecords(const string &fileName) {
        records.clear();
        ifstream fin;
        fin.open(fileName);
        if(!fin) {
            cerr << "Error opening file " << fileName << endl;
            return;
        }
        string line;
        while(getline(fin, line)) {
            stringstream ss(line);
            int adopterId, petId;
            ss >> adopterId >> petId;
            records.push_back({adopterId, petId});
        }
        fin.close();
    }

    void saveRecords(const string& fileName) const {
        ofstream fout;
        fout.open(fileName);
        if (!fout) {
            cerr << "Error opening file for writing " << fileName << endl;
            return;
        }
        for (const auto& record: records) {
            fout << record.first << " " << record.second << endl;
        }
        fout.close();
    }

    void displayRecords() const {
        cout << endl;
        setConsoleTextColor(ConsoleColor::Magenta);
        for (const auto& record : records) {
            cout << "Adopter ID: " << record.first << " adopted Pet ID: " << record.second << endl;
        }
        setConsoleTextColor(ConsoleColor::BrightWhite);
    }
};