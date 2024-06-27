#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "adopterCenter.h"
#include "userManager.h"
#include "userManager.h"
#include "volunteerManager.h"
#include "donationManager.h"
#include "termsAndConditions.h"
#include "costManager.h"
#include "../src/adoptionRecordManager.cpp"
using namespace std;

class Menu {
private:
    AdoptionCenter adoptionCenter;
    AdoptionRecordManagerChild* adoptionRecordManager;
    UserManager* userManager;
    VolunteerManager* volunteerManager;
    DonationManager* donationManager;
    bool isLoggedIn;
public:
    Menu(AdoptionCenter &center);
    ~Menu();
    void showMainMenu();
    void handleUserRegistration();
    void handleUserLogin();
    void handleAddPet();
    void handleAddAdopter();
    void handleAdoptPet();
    void handleVaccination();
    void handleDisplayAllPets();
    void handleDisplayAllAdopters();
    void handleDisplayAllVaccinations();
    void addTermToConditions();
    void handleDisplayTerms();
    void handleDisplayPetTypes();
    void handleDisplayVaccinationTypes();
    void handleAddVolunteer();
    void handleListVolunteers();
    void handleAddDonation();
    void handleListDonations();
    void handleSaveData();
    void handleLoadData();
};

#endif