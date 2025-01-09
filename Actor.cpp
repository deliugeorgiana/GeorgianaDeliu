#include "Actor.h"

// constr
Actor::Actor(std::string name) : name(std::move(name)) {}

// Adds a movie
void Actor::AddFilm(const std::shared_ptr<MediaItem>& item) {
    filmography.push_back(item);
}
void Actor::DisplayFilms() const {
    if (filmography.empty()) {
        std::cout << "No films available.\n";
    } else {
        for (const auto& film : filmography) {
            std::cout << film->GetTitle() << ", ";
        }
        std::cout << "\n";
    }
}

// Main role
[[nodiscard]] std::string Actor::GetMainRole() const {
    return !filmography.empty() ? filmography.front()->GetTitle() : "N/A";
}

//Role type
[[nodiscard]] std::string Actor::GetRoleType() const {
    return "Actor";
}

const std::string& Actor::GetName() const {
    return name;
}

// af obiecte actor <<
std::ostream& operator<<(std::ostream& os, const Actor& actor) {
    os << "Actor: " << actor.GetName() << ", Films: " << actor.filmography.size();
    return os;
}
