#include "TVShow.h"
#include <iostream>

float TVShow::GetRating() const {
    return rating;
}

std::string TVShow::GetType() const {
    return "TV Show";
}

std::shared_ptr<MediaItem> TVShow::Clone() const {
    return std::make_shared<TVShow>(*this);
}
