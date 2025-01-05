#ifndef FAVORITES_WATCHLIST_H
#define FAVORITES_WATCHLIST_H

#include "Watchlist.h"
#include <iostream>

// Watchlist specializat pentru favorite
template <typename T>
class FavoritesWatchlist : public Watchlist<T> {
public:
    explicit FavoritesWatchlist(std::string user) : Watchlist<T>(std::move(user)) {}

    void DisplayWatchlist() const override {
        std::cout << "Favorites Watchlist for " << this->userId << ":\n";
        for (const auto& item : this->items) {
            if (item.GetRating() > 8.0) {
                std::cout << item << std::endl;
            }
        }
    }
};

#endif
