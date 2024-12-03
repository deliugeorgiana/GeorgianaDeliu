#ifndef TVSHOW_H
#define TVSHOW_H

#include "MediaItem.h"

// clasa derivata emisiune tv
class TVShow : public MediaItem {
public:
    TVShow(std::string title, std::string description, float rating);

    //destructor
    ~TVShow() override = default;

    // fcn virt rating
    [[nodiscard]] float GetRating() const override;

    // fcn virtuala tip
    [[nodiscard]] std::string GetType() const override;

    // clona TvShow
    [[nodiscard]] std::shared_ptr<MediaItem> Clone() const override;
};

#endif
