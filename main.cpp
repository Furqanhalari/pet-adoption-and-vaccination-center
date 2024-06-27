#include <iostream>
#include <windows.h>

#include "./src/menu.cpp"
#include "./include/menu.h"
#include "./src/adopterCenter.cpp"
#include "./src/consoleUtils.cpp"
#include "./src/costManager.cpp"
#include "./src/vaccination.cpp"
using namespace std;

int main() {
    AdoptionCenter adoptionCenter(FileManager::loadPets(), FileManager::loadAdopters(), FileManager::loadVaccinations());
    Menu menu(adoptionCenter);
    menu.showMainMenu();
    return 0;
} 