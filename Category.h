#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <memory>

class Category {
protected:
    std::string name;

public:
    explicit Category(std::string name);

    virtual ~Category() = default;

    // fcn virt pura
    [[nodiscard]] virtual std::string GetCategoryName() const = 0;

    // fcn virt pura clona
    [[nodiscard]] virtual std::shared_ptr<Category> Clone() const = 0;

    // friend <<
    friend std::ostream& operator<<(std::ostream& os, const Category& category);
};

#endif
