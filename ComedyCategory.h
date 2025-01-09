#ifndef COMEDY_CATEGORY_H
#define COMEDY_CATEGORY_H

#include "Category.h"

// derived class
template <typename T>
class ComedyCategory : public Category<T> {
public:
    // Constructor explicit
    ComedyCategory(const std::string& name, T attribute)
            : Category<T>(name, attribute) {}

    ~ComedyCategory() override = default;

    // Suprascrierea metodei virtuale
    [[nodiscard]] std::string GetCategoryName() const override {
        return "Comedy: " + this->name + " (" + std::to_string(this->additionalAttribute) + ")";
    }
};

#endif
