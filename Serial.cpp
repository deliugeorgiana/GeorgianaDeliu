#include "Serial.h"

Serial::Serial([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    std::cout << "Creating serial: " << this->GetTitle()
              << ", " << this->GetDescription()
              << ", Rating: " << this->GetRating() << std::endl;
}


// Virtual function for rating
float Serial::GetRating() const {
    return rating;
}

//Virtual function for typew
std::string Serial::GetType() const {
    return "Serial";
}

// Clone
std::shared_ptr<MediaItem> Serial::Clone() const {
    return std::make_shared<Serial>(*this);
}
