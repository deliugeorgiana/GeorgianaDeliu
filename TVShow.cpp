#include "TVShow.h"
#include <iostream>

TVShow::TVShow([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    std::cout << "Creating TV Show: " << this->GetTitle()
              << ", " << this->GetDescription()
              << ", Rating: " << this->GetRating() << std::endl;
}

float TVShow::GetRating() const {
    return rating;
}

std::string TVShow::GetType() const {
    return "TV Show";
}

// Virtual function clone
std::shared_ptr<MediaItem> TVShow::Clone() const {
    return std::make_shared<TVShow>(*this);
}