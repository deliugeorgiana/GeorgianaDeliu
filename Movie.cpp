#include "Movie.h"


Movie::Movie([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating)
        : MediaItem(std::move(title), std::move(description), rating) {
    // Temporary copies
    const std::string titleCopy = this->GetTitle();
    const std::string descriptionCopy = this->GetDescription();

    std::cout << "Creating movie: " << titleCopy << ", " << descriptionCopy << ", Rating: " << rating << std::endl;
}


// Virtual function for rating
float Movie::GetRating() const {
    return rating;
}

// Virtual function for type
std::string Movie::GetType() const {
    return "Movie";
}

// Clone
std::shared_ptr<MediaItem> Movie::Clone() const {
    return std::make_shared<Movie>(*this);
}
