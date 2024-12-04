#include "TVShow.h"
#include <iostream>

TVShow::TVShow([[maybe_unused]] std::string title, std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
            std::string titleCopy = this->GetTitle();
            std::string descriptionCopy = this->GetDescription();

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
