#ifndef DRAMA_CATEGORY_H
#define DRAMA_CATEGORY_H

#include "Category.h"

class DramaCategory : public Category {
public:
    // constructor explicit
    explicit DramaCategory(const std::string& name);

    // suprascriere
    [[nodiscard]] std::string GetCategoryName() const override;

    // clone
    [[nodiscard]] std::shared_ptr<Category> Clone() const override;

    // destructor virt
    ~DramaCategory() override = default;
};

#endif
