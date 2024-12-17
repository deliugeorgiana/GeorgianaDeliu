#include "FavoritesWatchlist.h"
#include <iostream>

FavoritesWatchlist::FavoritesWatchlist([[maybe_unused]] std::string user) : Watchlist(std::move(user)) {}

void FavoritesWatchlist::DisplayWatchlist() const {
    std::cout << "Favorites Watchlist for " << userId << ":\n";
    for (const auto& item : items) {
        if (item->GetRating() > 8.0f) {
            std::cout << *item << std::endl;
        }
    }
}

