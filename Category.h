#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <memory>

// clasa template
template <typename T>
class Category {
protected:
    std::string name;
    T additionalAttribute; // atribut generic

public:
    // Constructor cu parametru generic
    explicit Category(std::string name, T attribute)
            : name(std::move(name)), additionalAttribute(std::move(attribute)) {}

    virtual ~Category() = default;

    // Funcție virtuală pură pentru a obține numele categoriei
    [[nodiscard]] virtual std::string GetCategoryName() const = 0;


    // Supradefinirea operatorului << pentru afișare
    friend std::ostream& operator<<(std::ostream& os, const Category& category) {
        os << category.GetCategoryName();
        return os;
    }
};

#endif
