#include "GuestActor.h"

[[maybe_unused]] GuestActor::GuestActor([[maybe_unused]] std::string name)
        : Actor(std::move(name)) {}

[[nodiscard]] std::string GuestActor::GetMainRole() const {
    return !filmography.empty() ? filmography.back()->GetTitle() : "N/A";
}

[[nodiscard]] std::string GuestActor::GetRoleType() const {
    return "Guest Actor";
}
