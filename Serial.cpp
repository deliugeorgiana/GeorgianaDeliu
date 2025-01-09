#include "Serial.h"

Serial::Serial([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    // Temporary copies
    const std::string titleCopy = this->GetTitle();
    const std::string descriptionCopy = this->GetDescription();

    std::cout << "Creating movie: " << titleCopy << ", " << descriptionCopy << ", Rating: " << rating << std::endl;
}


// Virtual function for rating
float Serial::GetRating() const {
    return rating;
}

// Clone
std::shared_ptr<MediaItem> Serial::Clone() const {
    return std::make_shared<Serial>(*this);
}
