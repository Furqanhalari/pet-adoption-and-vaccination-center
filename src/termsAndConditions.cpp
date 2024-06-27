#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/termsAndConditions.h"
#include "../include/consoleUtils.h"

using namespace std;

TermsAndConditions::TermsAndConditions() {
    loadTermsFromFile();
}

void TermsAndConditions::loadTermsFromFile() {
    terms.clear();
    ifstream inFile("data/termsAndCondition.txt");
    string line;
    while (getline(inFile, line)) {
        terms.push_back(line);
    }
    inFile.close();
}

void TermsAndConditions::addTerm(const std::string &term) {
    ofstream outFile("data/termsAndCondition.txt", ios::app);
    if (outFile.is_open()) {
        outFile << term << endl;
        outFile.close();
        terms.push_back(term);
    } else {
        cerr << "Error opening termsAndCondition.txt for writing." << endl;
    }
}

void TermsAndConditions::displayTerms() {
    cout << endl;
    setConsoleTextColor(ConsoleColor::LightMagenta);
    loadTermsFromFile();
    for (const auto &term : terms) {
        cout << term << endl;
    }
    setConsoleTextColor(ConsoleColor::BrightWhite);
}
