#include "SupportingActor.h"

[[maybe_unused]] SupportingActor::SupportingActor(const std::string& name) : Actor(name){
    std::cout << "SupportingActor created with name: " << name << std::endl;
}

[[nodiscard]] std::string SupportingActor::GetMainRole() const {
    return !filmography.empty() ? filmography.back()->GetTitle() : "N/A";
}

[[nodiscard]] std::string SupportingActor::GetRoleType() const {
    return "Supporting Actor";
}
