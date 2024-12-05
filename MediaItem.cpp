#include "MediaItem.h"


MediaItem::MediaItem(std::string title)
        : title(std::move(title)), rating(0.0f) {}

MediaItem::MediaItem(std::string title, std::string description, float rating)
        : title(std::move(title)), description(std::move(description)), rating(rating) {}

// getter title
const std::string& MediaItem::GetTitle() const {
    return title;
}

// getter description
const std::string& MediaItem::GetDescription() const {
    return description;
}

// info MediaItem
std::string MediaItem::GetInfo() const {
    return title + ": " + description;
}

// suprascriere a op <<
std::ostream& operator<<(std::ostream& os, const MediaItem& media) {
    os << "Title: " << media.GetTitle()
       << "\nDescription: " << media.GetDescription();
    return os;
}
