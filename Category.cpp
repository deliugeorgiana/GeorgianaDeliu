#include "Category.h"

//constructor
Category::Category(std::string name) : name(std::move(name)) {}

// op <<
std::ostream& operator<<(std::ostream& os, const Category& category) {
    os << category.GetCategoryName();
    return os;
}