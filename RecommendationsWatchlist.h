#ifndef RECOMMENDATIONS_WATCHLIST_H
#define RECOMMENDATIONS_WATCHLIST_H

#include "Watchlist.h"
#include <iostream>

// Watchlist specializat pentru recomandări
template <typename T>
class RecommendationsWatchlist : public Watchlist<T> {
public:
    explicit RecommendationsWatchlist(std::string user) : Watchlist<T>(std::move(user)) {}

    void DisplayWatchlist() const override {
        std::cout << "Recommended Watchlist for " << this->userId << ":\n";
        for (const auto& item : this->items) {
            // Exemplu: Afișăm doar elementele ce respectă o anumită condiție
            if (item.GetRating() >= 7.0 && item.GetRating() <= 8.0) {
                std::cout << item << std::endl;
            }
        }
    }
};

#endif
