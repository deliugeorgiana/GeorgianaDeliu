#ifndef WATCHLIST_UTILS_H
#define WATCHLIST_UTILS_H

#include "Watchlist.h"
#include <iostream>

template <typename T>
void DisplayWatchlistInfo(const Watchlist<T>& watchlist) {
    std::cout << "Displaying watchlist info:\n";
    watchlist.DisplayWatchlist();
}

#endif