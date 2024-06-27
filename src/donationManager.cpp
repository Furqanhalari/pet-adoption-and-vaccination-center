#include "../include/donationManager.h"
#include <iostream>
#include <fstream>
using namespace std;

class DonationManagerChild : public DonationManager {
private:
    vector<pair<string, double>> donations;

public:
    void addDonation(const string& donorName, double amount) {
        donations.push_back({donorName, amount});
    }

    void loadDonations(const string& filename) {
        donations.clear();
        ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error opening file for reading: " << filename << endl;
            return;
        }

        string donorName;
        double amount;
        while (inFile >> donorName >> amount) {
            donations.push_back({donorName, amount});
        }
        inFile.close();
    }

    void saveDonations(const string& filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error opening file for writing: " << filename << endl;
            return;
        }

        for (const auto& donation : donations) {
            outFile << donation.first << " " << donation.second << endl;
        }
        outFile.close();
    }

    void displayDonations() const {
        for (const auto& donation : donations) {
            cout << "Donor Name: " << donation.first << ", Amount: $" << donation.second << endl;
        }
    }
};
