#ifndef TERMS_AND_CONDITIONS_H
#define TERMS_AND_CONDITIONS_H

#include <vector>
#include <string>
using namespace std;

class TermsAndConditions {
private:
    vector<string> terms;
public:
    TermsAndConditions();
    void addTerm(const std::string &term);
    void displayTerms();
    void loadTermsFromFile();
};

#endif
