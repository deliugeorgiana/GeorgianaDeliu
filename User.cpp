#include "User.h"

void User::DisplayProfile() const {
    std::cout << "User: " << name << ", Language: " << preferredLanguage << ", Favorites: " << favorites.size() << std::endl;

    if (!favorites.empty()) {
        std::cout << "Top favorite: " << *favorites.front() << std::endl;
    } else {
        std::cout << "No favorite media items." << std::endl;
    }
}
