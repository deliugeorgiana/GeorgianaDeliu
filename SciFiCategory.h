#ifndef SCIFI_CATEGORY_H
#define SCIFI_CATEGORY_H

#include "Category.h"

template <typename T>
class SciFiCategory : public Category<T> {
public:
    // Constructor explicit
    SciFiCategory(const std::string& name, T attribute)
            : Category<T>(name, attribute) {}

    ~SciFiCategory() override = default;

    // Suprascrierea metodei virtuale
    [[nodiscard]] std::string GetCategoryName() const override {
        return "Sci-Fi: " + this->name + " (" + std::to_string(this->additionalAttribute) + ")";
    }
};

#endif
