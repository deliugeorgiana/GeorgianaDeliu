#ifndef RECOMMENDATIONS_WATCHLIST_H
#define RECOMMENDATIONS_WATCHLIST_H

#include "Watchlist.h"

class [[maybe_unused]] RecommendationsWatchlist : public Watchlist <std::shared_ptr<MediaItem>>{
public:
    explicit RecommendationsWatchlist([[maybe_unused]] std::string user);

    ~RecommendationsWatchlist() override =default;

    void DisplayWatchlist() const override;
};

#endif
