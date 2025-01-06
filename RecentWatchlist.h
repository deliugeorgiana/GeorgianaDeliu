#ifndef RECENT_WATCHLIST_H
#define RECENT_WATCHLIST_H

#include "Watchlist.h"

class [[maybe_unused]] RecentWatchlist : public Watchlist<std::shared_ptr<MediaItem>> {
public:
    explicit RecentWatchlist([[maybe_unused]] std::string user);

    ~RecentWatchlist() override =default;

    void DisplayWatchlist() const override;

};

#endif
