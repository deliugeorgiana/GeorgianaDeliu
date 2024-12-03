#include "ComedyCategory.h"

// constr explicit
ComedyCategory::ComedyCategory(const std::string& name)
        : Category(name) {}

[[nodiscard]] std::string ComedyCategory::GetCategoryName() const {
    return "Comedy: " + name;
}

//clonare
[[nodiscard]] std::shared_ptr<Category> ComedyCategory::Clone() const {
    return std::make_shared<ComedyCategory>(*this);
}
