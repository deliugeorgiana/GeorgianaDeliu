#include "DramaCategory.h"

// constr
DramaCategory::DramaCategory(const std::string& name) : Category(name) {}

// suprascriere
[[nodiscard]] std::string DramaCategory::GetCategoryName() const {
    return "Drama: " + name;  // Adăugăm un prefix pentru a indica că este o dramă
}

// clone
[[nodiscard]] std::shared_ptr<Category> DramaCategory::Clone() const {
    return std::make_shared<DramaCategory>(*this);  // Folosim shared_ptr pentru a crea o clonă
}
