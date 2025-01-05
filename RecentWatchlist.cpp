#include "RecentWatchlist.h"
#include <iostream>

// constr
RecentWatchlist::RecentWatchlist([[maybe_unused]] std::string user) : Watchlist(std::move(user)) {}

//suprascriere
void RecentWatchlist::DisplayWatchlist() const {
    std::cout << "Recent Watchlist for " << userId << ":\n";
    if (!items.empty()) {
        std::cout << *items.back() << std::endl;
    } else {
        std::cout << "No items to display.\n";
    }
}

