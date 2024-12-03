#include "GuestUser.h"
#include <iostream>

void GuestUser::DisplayProfile() const {
    std::cout << "[Guest] Name: " << GetName()
              << ", Language: " << GetPreferredLanguage() << std::endl;
}

std::shared_ptr<User> GuestUser::Clone() const {
    return std::make_shared<GuestUser>(*this);
}
