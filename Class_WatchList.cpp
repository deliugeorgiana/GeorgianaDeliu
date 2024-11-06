#ifndef WATCHLIST_H
#define WATCHLIST_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Class_Media_Item.cpp"

class Watchlist {
private:
    std::string userId;
    std::vector<std::shared_ptr<MediaItem>> items;

public:
    // Constructor
    [[maybe_unused]] explicit Watchlist(std::string user) : userId(std::move(user)) {}

    // Adaugă un element media la lista de vizionare
    void AddToWatchlist(const std::shared_ptr<MediaItem>& item) {
        items.push_back(item);
    }

    // Elimină un element media din lista de vizionare
    void RemoveFromWatchlist(const std::shared_ptr<MediaItem>& item) {
        items.erase(std::remove_if(items.begin(), items.end(),
                                   [&item](const std::shared_ptr<MediaItem>& i) { return i == item; }),
                    items.end());
    }

    // Afișează lista de vizionare
    void DisplayWatchlist() const {
        std::cout << "Watchlist for " << userId << ":\n";
        for (const auto& item : items) {
            std::cout << item << std::endl; // Folosim operatorul << pentru shared_ptr
        }
    }
};

#endif
