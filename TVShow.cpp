#include "TVShow.h"
#include <iostream>

TVShow::TVShow([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    // Temporary copies
    const std::string titleCopy = this->GetTitle();
    const std::string descriptionCopy = this->GetDescription();

    std::cout << "Creating movie: " << titleCopy << ", " << descriptionCopy << ", Rating: " << rating << std::endl;
}

float TVShow::GetRating() const {
    return rating;
}

std::string TVShow::GetType() const {
    return "TV Show";
}

std::shared_ptr<MediaItem> TVShow::Clone() const {
    return std::make_shared<TVShow>(*this);
}