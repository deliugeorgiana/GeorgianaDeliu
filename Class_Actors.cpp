#ifndef ACTORI_H
#define ACTORI_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Class_Media_Item.cpp"

class Actori {
private:
    std::string nume;
    std::vector<std::shared_ptr<MediaItem>> filmografie; // Use shared_ptr for filmografie

public:
    // Constructor explicit
    [[maybe_unused]] explicit Actori(std::string nume) : nume(std::move(nume)) {}

    // Constructor de copiere
    Actori(const Actori& other) = default;

    // Operator= de copiere
    Actori& operator=(const Actori& other) {
        if (this != &other) {
            nume = other.nume;
            filmografie = other.filmografie; // Use shared_ptr copy
        }
        return *this;
    }

    // Destructor
    ~Actori() = default;

    // Funcții publice
    void AddFilm(const std::shared_ptr<MediaItem>& item) {
        filmografie.push_back(item);
    }

    [[maybe_unused]] [[nodiscard]] size_t FilmCount() const { return filmografie.size(); }

    [[nodiscard]] std::string GetMainRole() const {
        return (!filmografie.empty()) ? filmografie.front()->GetInfo() : "N/A";
    }

    // Operator<<
    friend std::ostream& operator<<(std::ostream& os, const Actori& actor) {
        os << "Actor: " << actor.nume << ", Films: " << actor.filmografie.size();
        return os;
    }
};

#endif
