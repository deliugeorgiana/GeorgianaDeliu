#include "Serial.h"

Serial::Serial( std::string title, std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    std::cout << "Creating serial " << title << ", " << description<< ", Rating: " << rating << std::endl;

}

// fcn virtuala rating
float Serial::GetRating() const {
    return rating;
}

// fcn virtuala tip
std::string Serial::GetType() const {
    return "Serial";
}

// clona serial
std::shared_ptr<MediaItem> Serial::Clone() const {
    return std::make_shared<Serial>(*this);
}
