#include "SciFiCategory.h"

//constr explicit
SciFiCategory::SciFiCategory(const std::string& name)
        : Category(name) {}

// implementare fcn
[[nodiscard]] std::string SciFiCategory::GetCategoryName() const {
    return "Sci-Fi: " + name;
}

// implementare clone
[[nodiscard]] std::shared_ptr<Category> SciFiCategory::Clone() const {
    return std::make_shared<SciFiCategory>(*this);
}
