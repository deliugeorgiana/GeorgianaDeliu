#ifndef WATCHLIST_H
#define WATCHLIST_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "MediaItem.h"

class Watchlist {
protected:
    std::string userId;
    std::vector<std::shared_ptr<MediaItem>> items;

public:
    //constructor
    explicit Watchlist(std::string user);

    // destr virt
    virtual ~Watchlist() = default;

    // adauga media
    [[maybe_unused]] virtual void AddToWatchlist(const std::shared_ptr<MediaItem>& item);

    // scoate media
    [[maybe_unused]] virtual void RemoveFromWatchlist(const std::shared_ptr<MediaItem>& item);

    // afiseaza watchlist ul
    [[maybe_unused]] virtual void DisplayWatchlist() const;


};

#endif