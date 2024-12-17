#include "DramaCategory.h"

// constr
DramaCategory::DramaCategory(const std::string& name) : Category(name) {}

// suprascriere
[[nodiscard]] std::string DramaCategory::GetCategoryName() const {
    return "Drama: " + name;  // Adăugăm un prefix pentru a indica că este o dramă
}

