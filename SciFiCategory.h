#ifndef SCIFI_CATEGORY_H
#define SCIFI_CATEGORY_H

#include "Category.h"

// clasa derivata
class SciFiCategory : public Category {
public:
    // constr explicit
    explicit SciFiCategory(const std::string& name);

    ~SciFiCategory() override =default;

    // suprascriere
    [[nodiscard]] std::string GetCategoryName() const override;

    // clonare
    [[nodiscard]] std::shared_ptr<Category> Clone() const override;
};

#endif
