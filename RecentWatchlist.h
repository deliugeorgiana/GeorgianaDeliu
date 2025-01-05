#ifndef RECENT_WATCHLIST_H
#define RECENT_WATCHLIST_H

#include "Watchlist.h"
#include <iostream>

// Watchlist specializat pentru elementele recente
template <typename T>
class RecentWatchlist : public Watchlist<T> {
public:
    explicit RecentWatchlist(std::string user) : Watchlist<T>(std::move(user)) {}

    void DisplayWatchlist() const override {
        std::cout << "Recent Watchlist for " << this->userId << ":\n";
        if (!this->items.empty()) {
            // Afișează doar ultimul element adăugat
            std::cout << this->items.back() << std::endl;
        } else {
            std::cout << "No items to display.\n";
        }
    }
};

#endif
