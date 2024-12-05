#include "User.h"

void User::DisplayProfile() const {
    std::cout << "User: " << name << ", Language: " << preferredLanguage << ", Favorites: " << favorites.size() << std::endl;

    std::shared_ptr<MediaItem> topFavorite = GetTopFavorite();
    if (topFavorite) {
        std::cout << "Top favorite: " << *topFavorite << std::endl;
    } else {
        std::cout << "No favorite media items." << std::endl;
    }
}