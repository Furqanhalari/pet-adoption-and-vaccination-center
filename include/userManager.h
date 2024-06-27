#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>

class UserManager {
public:
    virtual ~UserManager() {};
    virtual void addUser(const string &userName, const string &password) = 0;
    virtual bool authenticateUser(const string &userName, const string &password) = 0;
    virtual void loadUsers(const string &filename) = 0;
    virtual void saveUsers(const string &filename) const = 0;
};

#endif