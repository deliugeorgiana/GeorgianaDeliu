#include "PremiumUser.h"
#include <iostream>

void PremiumUser::DisplayProfile() const {
    std::cout << "[Premium] Name: " << GetName()
              << ", Language: " << GetPreferredLanguage() << std::endl;
}


void PremiumUser::RecommendContent() const {
    std::cout << "Recommending content for: " << GetName()
              << " based on language: " << GetPreferredLanguage() << std::endl;
}