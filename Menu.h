#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>
#include "MediaItem.h"  // for MediaItem and derived classes

class Menu {
private:
    static Menu uniqueInstance;  // Singleton
    Menu() = default;            // Private constructor for Singleton

public:
    // Delete copy constructor and assignment operator
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    ~Menu() = default;

    // Return the unique instance of the class
    static Menu& instance();

    // Method to run the menu
    static void run();
};

#endif // MENU_H
