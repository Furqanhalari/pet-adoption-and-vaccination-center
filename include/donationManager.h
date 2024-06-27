#ifndef DONATIONMANAGER_H
#define DONATIONMANAGER_H

#include <string>
#include <vector>
using namespace std;

class DonationManager {
public:
    virtual ~DonationManager() {}
    virtual void addDonation(const string& donorName, double amount) = 0;
    virtual void loadDonations(const string& filename) = 0;
    virtual void saveDonations(const string& filename) const = 0;
    virtual void displayDonations() const = 0;
};

#endif