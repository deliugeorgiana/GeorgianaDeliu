#include "SciFiCategory.h"

//constr explicit
SciFiCategory::SciFiCategory(const std::string& name)
        : Category(name) {}

// implementare fcn
[[nodiscard]] std::string SciFiCategory::GetCategoryName() const {
    return "Sci-Fi: " + name;
}
