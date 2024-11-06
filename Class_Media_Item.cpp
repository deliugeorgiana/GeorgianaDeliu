#ifndef MEDIA_ITEM_H
#define MEDIA_ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class MediaItem {
private:
    std::string title;
    int releaseYear;
    float rating;
    std::vector<std::string> genres;

public:
    // Constructor fără parametrii
    MediaItem() : releaseYear(0), rating(0.0f) {}

    // Constructor inițializare (explicit)
    explicit MediaItem(std::string title, int year, float rating)
            : title(std::move(title)), releaseYear(year), rating(rating) {}

    // Constructor de copiere
    MediaItem(const MediaItem& other) = default;

    // Operator= de copiere
    MediaItem& operator=(const MediaItem& other) {
        if (this != &other) {
            title = other.title;
            releaseYear = other.releaseYear;
            rating = other.rating;
            genres = other.genres;
        }
        return *this;
    }

    // Destructor
    ~MediaItem() = default;

    // Funcții publice
    void AddGenre(std::string genre) {
        genres.push_back(std::move(genre));
    }

    [[nodiscard]] std::string GetInfo() const {
        return title + " (" + std::to_string(releaseYear) + ") - Rating: " + std::to_string(rating);
    }

    // Operator<<
    friend std::ostream& operator<<(std::ostream& os, const MediaItem& item) {
        os << "Title: " << item.title << ", Year: " << item.releaseYear << ", Rating: " << item.rating;
        return os;
    }
};

// Operator<< pentru shared_ptr<MediaItem>
inline std::ostream& operator<<(std::ostream& os, const std::shared_ptr<MediaItem>& item) {
    if (item) {
        os << *item;
    } else {
        os << "nullptr";
    }
    return os;
}

#endif
