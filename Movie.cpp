#include "Movie.h"


Movie::Movie(std::string title, std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
        std::cout << "Creating movie: " << title << ", " << description << ", Rating: " << rating << std::endl;
}

// dcn virtuala pt a scoate rating
float Movie::GetRating() const {
    return rating;
}

// functie virtuala pt tip
std::string Movie::GetType() const {
    return "Movie";
}

// clona
std::shared_ptr<MediaItem> Movie::Clone() const {
    return std::make_shared<Movie>(*this);
}
