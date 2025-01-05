#include "Watchlist.h"

// constructor
Watchlist::Watchlist(std::string user) : userId(std::move(user)) {}

//adauga media
[[maybe_unused]] void Watchlist::AddToWatchlist(const std::shared_ptr<MediaItem>& item) {
    items.push_back(item);
}

// scoate media de pe watchlist
[[maybe_unused]] void Watchlist::RemoveFromWatchlist(const std::shared_ptr<MediaItem>& item) {
    items.erase(std::remove(items.begin(), items.end(), item), items.end());
}

// afis
[[maybe_unused]] void Watchlist::DisplayWatchlist() const {
    std::cout << "Watchlist for " << userId << ":\n";
    for (const auto& item : items) {
        std::cout << *item << std::endl;
    }
}