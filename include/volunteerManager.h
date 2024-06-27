#ifndef VOLUNTEERMANAGER_H
#define VOLUNTEERMANAGER_H

#include <string>
using namespace std;

class VolunteerManager {
public:
    virtual ~VolunteerManager() {};
    virtual void addVolunteer(const string& name, const string& contact) = 0;
    virtual void loadVolunteers(const string& filename) = 0;
    virtual void saveVolunteers(const string& filename) const = 0;
    virtual void displayVolunteers() const = 0;
};

#endif