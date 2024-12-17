#include "ComedyCategory.h"

// constr explicit
ComedyCategory::ComedyCategory(const std::string& name)
        : Category(name) {}

[[nodiscard]] std::string ComedyCategory::GetCategoryName() const {
    return "Comedy: " + name;
}

