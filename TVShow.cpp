#include "TVShow.h"
#include <iostream>

TVShow::TVShow(std::string title, std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
        std::cout << "Creating TV Show: " << title << ", " << description << ", Rating: " << rating << std::endl;
}

float TVShow::GetRating() const {
    return rating;
}

std::string TVShow::GetType() const {
    return "TV Show";
}

// fcn clone
std::shared_ptr<MediaItem> TVShow::Clone() const {
    return std::make_shared<TVShow>(*this);
}
