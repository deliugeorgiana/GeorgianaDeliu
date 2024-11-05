#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Class_Media_Item.cpp"

class Categorie {
private:
    std::string numeCategorie;
    std::vector<std::shared_ptr<MediaItem>> listaFilme; // Use shared_ptr for media items
    int popularitate;

public:
    // Constructor explicit
    explicit Categorie(std::string nume, int popularitate = 0)
            : numeCategorie(std::move(nume)), popularitate(popularitate) {}

    // Constructor de copiere
    Categorie(const Categorie& other) = default;

    // Operator= de copiere
    Categorie& operator=(const Categorie& other) {
        if (this != &other) {
            numeCategorie = other.numeCategorie;
            listaFilme = other.listaFilme; // Use shared_ptr copy
            popularitate = other.popularitate;
        }
        return *this;
    }

    // Destructor
    ~Categorie() = default;

    // Funcții publice
    void AddMediaItem(const std::shared_ptr<MediaItem>& item) {
        listaFilme.push_back(item);
    }

    [[nodiscard]] bool IsPopular() const { return popularitate > 100; }

    [[nodiscard]] std::shared_ptr<MediaItem> GetTopItem() const {
        return (!listaFilme.empty()) ? listaFilme.front() : nullptr;
    }

    // Operator<<
    friend std::ostream& operator<<(std::ostream& os, const Categorie& categorie) {
        os << "Category: " << categorie.numeCategorie << ", Popularity: " << categorie.popularitate;
        return os;
    }
};

#endif
