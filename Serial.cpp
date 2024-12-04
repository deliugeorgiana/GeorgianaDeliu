#include "Serial.h"

Serial::Serial([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
            std::string titleCopy = this->GetTitle();
            std::string descriptionCopy = this->GetDescription();

}

// Virtual function for rating
float Serial::GetRating() const {
    return rating;
}

// Virtual function for type
std::string Serial::GetType() const {
    return "Serial";
}

// Clone for serial
std::shared_ptr<MediaItem> Serial::Clone() const {
    return std::make_shared<Serial>(*this);
}
