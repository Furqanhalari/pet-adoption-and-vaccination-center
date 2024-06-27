#include "../include/userManager.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

class UserManagerChild: public UserManager {
private:
    unordered_map<string, string> users;
public:
    void addUser(const string &userName, const string &password) {
        users[userName] = password;
    }

    bool authenticateUser(const string &userName, const string &password) {
        return users.find(userName) != users.end() && users[userName] == password;
    }

    void loadUsers(const string &filename) {
        users.clear();
        ifstream fin;
        fin.open(filename);
        if (!fin) {
            cerr << "Error opening file for reading " << filename << endl;
            return;
        }
        string username, password;
        while(fin >> username >> password) {
            users[username] = password;
        }
        fin.close();
    }

    void saveUsers(const string &filename) const {
        ofstream fout;
        fout.open(filename);
        if (!fout) {
            cerr << "Error opening file for writing " << filename << endl;
            return;
        }
        for (const auto& user: users) {
            fout << user.first << " " << user.second << endl;
        }
        fout.close();
    }
};