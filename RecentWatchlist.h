#ifndef RECENT_WATCHLIST_H
#define RECENT_WATCHLIST_H

#include "Watchlist.h"

class [[maybe_unused]] RecentWatchlist : public Watchlist {
public:
    explicit RecentWatchlist([[maybe_unused]] std::string user);

    ~RecentWatchlist() override =default;

    void DisplayWatchlist() const override;

    [[nodiscard]] std::unique_ptr<Watchlist> Clone() const override;
};

#endif
