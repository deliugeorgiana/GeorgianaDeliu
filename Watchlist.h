#ifndef WATCHLIST_H
#define WATCHLIST_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "MediaItem.h"

template <typename T>
class Watchlist {
protected:
    std::string userId;
    std::vector<T> items;
    T favoriteItem; // Atribut de tip T

public:
    // Constructor
    explicit Watchlist(std::string user) : userId(std::move(user)) {}

    // Destructor virtual
    virtual ~Watchlist() = default;

    // Adaugă media
    virtual void AddToWatchlist(const T& item) {
        items.push_back(item);
    }



    // Afișează watchlist-ul
    virtual void DisplayWatchlist() const {
        std::cout << "Watchlist for " << userId << ":\n";
        for (const auto& item : items) {
            std::cout << *item << "\n";
        }
    }
};

#endif