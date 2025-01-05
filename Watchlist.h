#ifndef WATCHLIST_H
#define WATCHLIST_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>

// Clasa șablon
template <typename T>
class Watchlist {
protected:
    std::string userId;
    std::vector<T> items;

public:
    explicit Watchlist(std::string user) : userId(std::move(user)) {}

    virtual ~Watchlist() = default;

    // Adaugă element în watchlist
    virtual void AddToWatchlist(const T& item) {
        items.push_back(item);
    }

    // Scoate element din watchlist
    virtual void RemoveFromWatchlist(const T& item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    // Afișează watchlist-ul
    virtual void DisplayWatchlist() const {
        std::cout << "Watchlist for " << userId << ":\n";
        for (const auto& item : items) {
            std::cout << item << std::endl;
        }
    }

    // Filtrează elementele după un predicat
    std::vector<T> Filter(const std::function<bool(const T&)>& predicate) const {
        std::vector<T> result;
        std::copy_if(items.begin(), items.end(), std::back_inserter(result), predicate);
        return result;
    }
};

// Funcție liberă șablon - comparare două watchlist-uri
template <typename T>
bool CompareWatchlists(const Watchlist<T>& wl1, const Watchlist<T>& wl2) {
    return wl1.items == wl2.items;
}

#endif
