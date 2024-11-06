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
    std::vector<std::shared_ptr<MediaItem>> filmografie;

public:
    [[maybe_unused]] explicit Actori(std::string nume) : nume(std::move(nume)) {}

    Actori(const Actori& other) = default;

    Actori& operator=(const Actori& other) {
        if (this != &other) {
            nume = other.nume;
            filmografie = other.filmografie;
        }
        return *this;
    }

    ~Actori() = default;

    void AddFilm(const std::shared_ptr<MediaItem>& item) {
        filmografie.push_back(item);
    }

    [[nodiscard]] size_t FilmCount() const { return filmografie.size(); }

    [[nodiscard]] std::string GetMainRole() const {
        return (!filmografie.empty()) ? filmografie.front()->GetInfo() : "N/A";
    }

    friend std::ostream& operator<<(std::ostream& os, const Actori& actor) {
        os << "Actor: " << actor.nume << ", Films: " << actor.filmografie.size();
        return os;
    }
};

#endif
