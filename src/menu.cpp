#include "../include/menu.h"
#include <iostream>
#include "../include/fileManager.h"
#include "../include/consoleUtils.h"
#include "userManager.cpp"
#include "volunteerManager.cpp"
#include "donationManager.cpp"
using namespace std;

Menu::Menu(AdoptionCenter &center) : adoptionCenter(center)
{
    adoptionRecordManager = new AdoptionRecordManagerChild();
    userManager = new UserManagerChild();
    volunteerManager = new VolunteerManagerChild();
    donationManager = new DonationManagerChild();
    isLoggedIn = false;
    userManager->loadUsers("data/users.txt");
}

Menu::~Menu()
{
    delete adoptionRecordManager;
    delete userManager;
    delete volunteerManager;
    delete donationManager;
}

void Menu::showMainMenu()
{
    int choice;
    do
    {
        setConsoleTextColor(ConsoleColor::LightCyan);
        cout << "\nPet Adoption and Vaccination Center\n";
        setConsoleTextColor(ConsoleColor::BrightWhite);
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Add Pet\n";
        cout << "4. Add Adopter\n";
        cout << "5. Adopt Pet\n";
        cout << "6. Add Vaccination\n";
        cout << "7. Display All Pets\n";
        cout << "8. Display All Adopters\n";
        cout << "9. Display All Vaccinations\n";
        cout << "10. Add term to terms and conditions\n";
        cout << "11. Display Terms and Conditions\n";
        cout << "12. Display Pet Types\n";
        cout << "13. Display Vaccination Types\n";
        cout << "14. Add Volunteer\n";
        cout << "15. Display All Volunteers\n";
        cout << "16. Add Donations\n";
        cout << "17. Display All Donations\n";
        cout << "18. Save Data\n";
        cout << "19. Load Data\n";
        cout << "20. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            handleUserRegistration();
            break;
        case 2:
            handleUserLogin();
            break;
        case 3:
            if (isLoggedIn)
                handleAddPet();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 4:
            if (isLoggedIn)
                handleAddAdopter();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 5:
            if (isLoggedIn)
                handleAdoptPet();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 6:
            if (isLoggedIn)
                handleVaccination();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 7:
            if (isLoggedIn)
                handleDisplayAllPets();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 8:
            if (isLoggedIn)
                handleDisplayAllAdopters();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 9:
            if (isLoggedIn)
                handleDisplayAllVaccinations();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 10:
            if (isLoggedIn)
                addTermToConditions();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 11:
            handleDisplayTerms();
            break;
        case 12:
            handleDisplayPetTypes();
            break;
        case 13:
            handleDisplayVaccinationTypes();
            break;
        case 14:
            if (isLoggedIn)
                handleAddVolunteer();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 15:
            if (isLoggedIn)
                handleListVolunteers();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 16:
            if (isLoggedIn)
                handleAddDonation();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 17:
            if (isLoggedIn)
                handleListDonations();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 18:
            if (isLoggedIn)
                handleSaveData();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 19:
            if (isLoggedIn)
                handleLoadData();
            else
                setConsoleTextColor(ConsoleColor::Red);
                cout << "Please login first.\n";
                setConsoleTextColor(ConsoleColor::BrightWhite);
            break;
        case 20:
            cout << "Exiting..\n";
            break;
        default:
            setConsoleTextColor(ConsoleColor::Red);
            cout << "Invalid Choice. Try again.\n";
            setConsoleTextColor(ConsoleColor::BrightWhite);
        }
    } while (choice != 20);
}

void Menu::handleUserRegistration() {
    string userName, password;
    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;
    userManager->addUser(userName, password);
    userManager->saveUsers("data/users.txt");
    setConsoleTextColor(ConsoleColor::Green);
    cout << "User registered successfully.\n";
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleUserLogin()
{
    string userName, password;
    cout << "Enter username: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;
    if (userManager->authenticateUser(userName, password))
    {
        isLoggedIn = true;
        setConsoleTextColor(ConsoleColor::Green);
        cout << "Login successful.\n";
        setConsoleTextColor(ConsoleColor::BrightWhite);
    }
    else
    {
        setConsoleTextColor(ConsoleColor::Red);
        cout << "Invalid username or password.\n";
        setConsoleTextColor(ConsoleColor::BrightWhite);
    }
}

void Menu::handleAddPet()
{
    cout << endl;
    int id, age;
    string name, type, breed, gender;

    cout << "Enter Pet ID: ";
    cin >> id;
    cout << "Enter Pet Name: ";
    cin >> name;
    cout << "Enter Pet Type (e.g., dog, cat): ";
    cin >> type;
    cout << "Enter Pet Age: ";
    cin >> age;
    cout << "Enter Pet Breed: ";
    cin >> breed;
    cout << "Enter Pet Gender: ";
    cin >> gender;

    Pet newPet(id, name, type, age, breed, gender, false);
    adoptionCenter.addPet(newPet);
    cout << "Pet added successfully.\n";
}

void Menu::handleAddAdopter()
{
    cout << endl;
    int id;
    string name, address, phoneNumber;

    cout << "Enter Adopter ID: ";
    cin >> id;
    cout << "Enter Adopter Name: ";
    cin >> name;
    cout << "Enter Adopter Address: ";
    cin >> address;
    cout << "Enter Adopter Phone Number: ";
    cin >> phoneNumber;

    Adopter newAdopter(id, name, address, phoneNumber);
    adoptionCenter.addAdopter(newAdopter);
    cout << "Adopter added successfully.\n";
}

void Menu::handleAdoptPet()
{
    cout << endl;
    int petId, adopterId;

    setConsoleTextColor(ConsoleColor::BrightWhite);
    cout << "Enter Pet ID to adopt: ";
    cin >> petId;
    cout << "Enter Adopter ID: ";
    cin >> adopterId;

    Pet *pet = adoptionCenter.findPetById(petId);
    Adopter *adopter = adoptionCenter.findAdopterById(adopterId);

    if (pet && adopter)
    {
        // Display terms and conditions
        TermsAndConditions terms;
        terms.displayTerms();

        char agree;
        cout << "Do you agree to the terms and conditions? (y/n): ";
        cin >> agree;

        if (agree == 'y' || agree == 'Y')
        {
            // Calculate and display adoption fee
            double fee = CostManager::getAdoptionFees(pet->getType());
            setConsoleTextColor(ConsoleColor::Green);
            cout << "Adoption Fee for " << pet->getType() << ": $" << fee << endl;

            // Simulate payment processing
            setConsoleTextColor(ConsoleColor::Cyan);
            cout << "Processing payment...\n";
            // Here you can add actual payment processing logic if needed
            cout << "Payment successful.\n";

            // Mark the pet as adopted and update adopter's record
            adoptionCenter.adoptPet(petId, adopterId);
            pet->markAdopted();
            adopter->addAdoptedPet(petId);

            // Add adoption record and save it
            adoptionRecordManager->addRecord(adopterId, petId);
            adoptionRecordManager->saveRecords("data/adoption_records.txt");

            setConsoleTextColor(ConsoleColor::Green);
            cout << "Pet adopted successfully.\n";
        }
        else
        {
            setConsoleTextColor(ConsoleColor::Red);
            cout << "Adoption cancelled.\n";
        }
    }
    else
    {
        setConsoleTextColor(ConsoleColor::Red);
        cout << "Invalid Pet ID or Adopter ID.\n";
    }
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleVaccination()
{
    cout << endl;
    int id, petId;
    string name, dateAdministered;

    cout << "Enter Vaccination ID: ";
    cin >> id;
    cout << "Enter Vaccination Name (e.g., rabies, distemper): ";
    cin >> name;
    cout << "Enter Date Administered: ";
    cin >> dateAdministered;
    cout << "Enter Pet ID: ";
    cin >> petId;

    Vaccination newVaccination(id, name, dateAdministered, petId);
    adoptionCenter.addVaccination(newVaccination);
    cout << "Vaccination added successfully.\n";
}

void Menu::handleDisplayAllPets()
{
    cout << endl;
    adoptionCenter.displayAllPets();
}

void Menu::handleDisplayAllAdopters()
{
    cout << endl;
    adoptionCenter.displayAllAdopters();
}

void Menu::handleDisplayAllVaccinations()
{
    cout << endl;
    adoptionCenter.displayAllVaccination();
}

void Menu::addTermToConditions()
{
    cout << endl;
    cin.ignore();
    cout << "Enter the new term: ";
    string newTerm;
    getline(cin, newTerm);

    TermsAndConditions terms;
    terms.addTerm(newTerm);

    setConsoleTextColor(ConsoleColor::Green);
    cout << "New term added successfully.\n";
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleDisplayTerms()
{
    cout << endl;
    TermsAndConditions terms;
    terms.displayTerms();
}

void Menu::handleDisplayPetTypes()
{
    setConsoleTextColor(ConsoleColor::Green);
    cout << endl;
    cout << "Available Pet Types and Costs:\n";
    cout << "1. Dog - $" << CostManager::getAdoptionFees("Dog") << "\n";
    cout << "2. Cat - $" << CostManager::getAdoptionFees("Cat") << "\n";
    cout << "3. Rabbit - $" << CostManager::getAdoptionFees("Rabbit") << "\n";
    cout << "4. Bird - $" << CostManager::getAdoptionFees("Bird") << "\n";
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleDisplayVaccinationTypes()
{
    setConsoleTextColor(ConsoleColor::Yellow);
    cout << endl;
    cout << "Available Vaccination Types and Costs:\n";
    cout << "1. Rabies - $" << CostManager::getVaccinationFees("Rabies") << "\n";
    cout << "2. Distemper - $" << CostManager::getVaccinationFees("Distemper") << "\n";
    cout << "3. Parvovirus - $" << CostManager::getVaccinationFees("Parvovirus") << "\n";
    cout << "4. Hepatitis - $" << CostManager::getVaccinationFees("Hepatitis") << "\n";
    cout << "5. Bordetella - $" << CostManager::getVaccinationFees("Bordetella") << "\n";
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleAddVolunteer()
{
    cout << endl;
    string name, contact;
    cout << "Enter Volunteer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Volunteer Contact: ";
    getline(cin, contact);

    volunteerManager->addVolunteer(name, contact);
    cout << "Volunteer added successfully.\n";
}

void Menu::handleListVolunteers()
{
    cout << endl;
    setConsoleTextColor(ConsoleColor::LightBlue);
    cout << "List of Volunteers:\n";
    volunteerManager->displayVolunteers();
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleAddDonation()
{
    cout << endl;
    string donorName;
    double amount;
    cout << "Enter Donor Name: ";
    cin.ignore();
    getline(cin, donorName);
    cout << "Enter Donation Amount: ";
    cin >> amount;

    donationManager->addDonation(donorName, amount);
    cout << "Donation added successfully.\n";
}

void Menu::handleListDonations()
{
    cout << endl;
    setConsoleTextColor(ConsoleColor::LightRed);
    cout << "List of Donations:\n";
    donationManager->displayDonations();
    setConsoleTextColor(ConsoleColor::BrightWhite);
}

void Menu::handleSaveData()
{
    FileManager::savePets(adoptionCenter.getPets());
    FileManager::saveAdopters(adoptionCenter.getAdopters());
    FileManager::saveVaccinations(adoptionCenter.getVaccinations());
    volunteerManager->saveVolunteers("data/volunteers.txt");
    donationManager->saveDonations("data/donations.txt");
    cout << "Data saved successfully.\n";
}

void Menu::handleLoadData()
{
    adoptionCenter.setPets(FileManager::loadPets());
    adoptionCenter.setAdopters(FileManager::loadAdopters());
    adoptionCenter.setVaccinations(FileManager::loadVaccinations());
    adoptionRecordManager->loadRecords("data/adoption_records.txt");
    volunteerManager->loadVolunteers("data/volunteers.txt");
    donationManager->loadDonations("data/donations.txt");
    cout << endl;
    setConsoleTextColor(ConsoleColor::Magenta);
    cout << "Data loaded successfully.\n";
    setConsoleTextColor(ConsoleColor::BrightWhite);
    cout << endl;
    handleDisplayAllPets();
    handleDisplayAllAdopters();
    handleDisplayAllVaccinations();
    handleListVolunteers();
    handleListDonations();
    adoptionRecordManager->displayRecords();
}