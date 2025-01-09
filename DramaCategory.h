#ifndef DRAMA_CATEGORY_H
#define DRAMA_CATEGORY_H

#include "Category.h"

template <typename T>
class DramaCategory : public Category<T> {
public:
    // Constructor explicit
    DramaCategory(const std::string& name, T attribute)
            : Category<T>(name, attribute) {}

    ~DramaCategory() override = default;

    // Suprascrierea metodei virtuale
    [[nodiscard]] std::string GetCategoryName() const override {
        return "Drama: " + this->name + " (" + std::to_string(this->additionalAttribute) + ")";
    }
};

#endif
