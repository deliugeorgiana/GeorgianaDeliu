#include "RecommendationsWatchlist.h"
#include <iostream>

// constr
RecommendationsWatchlist::RecommendationsWatchlist([[maybe_unused]] std::string user) : Watchlist(std::move(user)) {}

// suprascriere
void RecommendationsWatchlist::DisplayWatchlist() const {
    std::cout << "Recommended Watchlist for " << userId << ":\n";
    for (const auto& item : items) {
        if (item->GetRating() >= 7.0f && item->GetRating() <= 8.0f) { // Items in a specific rating range
            std::cout << *item << std::endl;
        }
    }
}

// clona
std::unique_ptr<Watchlist> RecommendationsWatchlist::Clone() const {
    return std::make_unique<RecommendationsWatchlist>(*this);
}
