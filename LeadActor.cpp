#include "LeadActor.h"
#include <iostream>


[[maybe_unused]] LeadActor::LeadActor([[maybe_unused]] std::string name) : Actor(std::move(name)) {
    std::cout << "LeadActor created with name: " << this->name << std::endl;
}

[[nodiscard]] std::string LeadActor::GetMainRole() const {
    return !filmography.empty() ? filmography.front()->GetTitle() : "N/A";
}

[[nodiscard]] std::string LeadActor::GetRoleType() const {
    return "Lead Actor";
}
