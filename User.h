#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "MediaItem.h"

class User {
protected:
    std::string name;
    std::string preferredLanguage;
    std::vector<std::shared_ptr<MediaItem>> favorites;

public:
    explicit User(std::string name, std::string preferredLanguage)
            : name(std::move(name)), preferredLanguage(std::move(preferredLanguage)) {}

    User(const User& other) = default;

    User& operator=(const User& other) {
        if (this != &other) {
            name = other.name;
            preferredLanguage = other.preferredLanguage;
            favorites = other.favorites;
        }
        return *this;
    }

    virtual ~User() = default;

    [[maybe_unused]] void AddToFavorites(const std::shared_ptr<MediaItem>& item) {
        favorites.push_back(item);
    }

    [[nodiscard]] std::shared_ptr<MediaItem> GetTopFavorite() const {
        if (!favorites.empty()) return favorites.front();
        return nullptr;
    }

    [[nodiscard]] size_t FavoriteCount() const { return favorites.size(); }

    // getteri
    [[nodiscard]] const std::string& GetName() const { return name; }
    [[nodiscard]] const std::string& GetPreferredLanguage() const { return preferredLanguage; }

    // fcn virt pura
    virtual void DisplayProfile() const = 0;

    // fcn virtuala clonare
    [[nodiscard]] virtual std::shared_ptr<User> Clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "User: " << user.name
           << ", Language: " << user.preferredLanguage
           << ", Favorites: " << user.favorites.size();
        return os;
    }
};

#endif
