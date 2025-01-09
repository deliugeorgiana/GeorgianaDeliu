#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "MediaItem.h"

template <typename T>
class User {
protected:
    std::string name;
    std::string preferredLanguage;
    std::vector<T> favorites;  // Favorite items can now be of any type T

public:
    // Constructor cu validare
    explicit User(std::string name, std::string preferredLanguage)
            : name(std::move(name)), preferredLanguage(std::move(preferredLanguage)) {
        if (this->name.empty() || this->preferredLanguage.empty()) {
            throw std::invalid_argument("Name and preferred language cannot be empty.");
        }
    }

    // Constructor de copiere
    User(const User& other) = default;

    // Operator de atribuire
    User& operator=(const User& other) {
        if (this != &other) {
            name = other.name;
            preferredLanguage = other.preferredLanguage;
            favorites = other.favorites;
        }
        return *this;
    }

    // Destructor virtual
    virtual ~User() = default;

    // Adaugă un element în lista de favorite
    void AddToFavorites(const T& item) {
        favorites.push_back(item);
    }

    // Obține primul element favorit
    [[nodiscard]] T GetTopFavorite() const {
        if (!favorites.empty()) return favorites.front();
        return T{};  // Return a default-constructed T if no favorites
    }

    // Obține numărul de elemente favorite
    [[nodiscard]] size_t FavoriteCount() const { return favorites.size(); }

    // Getteri virtuali
    [[nodiscard]] virtual const std::string& GetName() const { return name; }
    [[nodiscard]] virtual const std::string& GetPreferredLanguage() const { return preferredLanguage; }

    // Funcție virtuală pură pentru afișare profil
    virtual void DisplayProfile() const = 0;

    // Suprascriere operator << pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "User: " << user.name
           << ", Language: " << user.preferredLanguage
           << ", Favorites: " << user.favorites.size();
        return os;
    }

    // Funcție șablon
    template <typename U>
    void PrintFavoriteDetails(const U& favorite) const {
        std::cout << "Favorite item details: " << favorite << std::endl;
    }
};

#endif // USER_H
