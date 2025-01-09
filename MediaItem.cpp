#include "MediaItem.h"

int MediaItem::itemCount = 0;
std::vector<std::string> MediaItem::genres;

MediaItem::MediaItem(std::string title)
        : title(std::move(title)), rating(0.0f) {
    ++itemCount;
}

MediaItem::MediaItem(std::string title, std::string description, float rating)
        : title(std::move(title)), description(std::move(description)), rating(rating) {
    ++itemCount;
}

// getter title
const std::string& MediaItem::GetTitle() const {
    return title;
}

// getter description
const std::string& MediaItem::GetDescription() const {
    return description;
}

// suprascriere a op <<
std::ostream& operator<<(std::ostream& os, const MediaItem& media) {
    os << "Title: " << media.GetTitle()
       << "\nDescription: " << media.GetDescription();
    return os;
}

// Static function implementations
[[maybe_unused]] int MediaItem::GetItemCount() {
    return itemCount;
}

[[maybe_unused]] void MediaItem::AddGenre(const std::string& genre) {
    genres.push_back(genre);
}

[[maybe_unused]] const std::vector<std::string>& MediaItem::GetGenres() {
    return genres;
}
