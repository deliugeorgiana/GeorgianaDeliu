
#include "Movie.h"


Movie::Movie([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    std::cout << "Creating movie: " << this->GetTitle()
              << ", " << this->GetDescription()
              << ", Rating: " << this->GetRating() << std::endl;
}


// Virtual function for rating

float Movie::GetRating() const {
    return rating;
}

// Virtual function for type
std::string Movie::GetType() const {
    return "Movie";
}