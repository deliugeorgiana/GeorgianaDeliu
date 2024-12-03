#include "Actor.h"

// constr
Actor::Actor(std::string name) : name(std::move(name)) {}

// adauga film la filmografie
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


// afla rolul principal
[[nodiscard]] std::string Actor::GetMainRole() const {
    return !filmography.empty() ? filmography.front()->GetTitle() : "N/A";
}

// primeste tipul rolului
[[nodiscard]] std::string Actor::GetRoleType() const {
    return "Actor";  // This is a generic "Actor" role, can be overridden by derived classes
}

// primeste numele actorului
[[nodiscard]] std::string Actor::GetName() const {
    return name;
}

// af obiecte actor <<
std::ostream& operator<<(std::ostream& os, const Actor& actor) {
    os << "Actor: " << actor.GetName() << ", Films: " << actor.filmography.size();
    return os;
}
