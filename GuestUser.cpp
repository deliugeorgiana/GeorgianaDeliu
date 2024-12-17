#include "GuestUser.h"
#include <iostream>

void GuestUser::DisplayProfile() const {
    std::cout << "[Guest] Name: " << GetName()
              << ", Language: " << GetPreferredLanguage() << std::endl;
}

