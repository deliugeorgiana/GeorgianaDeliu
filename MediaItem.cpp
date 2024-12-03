#include "MediaItem.h"

// constructor primeste titlu si initializeaza ratingul
MediaItem::MediaItem(std::string title)
        : title(std::move(title)), rating(0.0f) {}

// constructorul initializeaza toate atributele din parametrii primiti
MediaItem::MediaItem(std::string title, std::string description, float rating)
        : title(std::move(title)), description(std::move(description)), rating(rating) {}

// getter titlu
std::string MediaItem::GetTitle() const {
    return title;
}

// fetter descriere
std::string MediaItem::GetDescription() const {
    return description;
}

// info MediaItemm
std::string MediaItem::GetInfo() const {
    return title + ": " + description;
}

// suprasciere a op <<
std::ostream& operator<<(std::ostream& os, const MediaItem& media) {
    os << "Title: " << media.GetTitle()
       << "\nDescription: " << media.GetDescription();
    return os;
}
