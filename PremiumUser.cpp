#include "PremiumUser.h"
#include <iostream>

void PremiumUser::DisplayProfile() const {
    std::cout << "[Premium] Name: " << GetName()
              << ", Language: " << GetPreferredLanguage() << std::endl;
}

//face si returneaza un obiect clonat
std::shared_ptr<User> PremiumUser::Clone() const {
    return std::make_shared<PremiumUser>(*this);
}

void PremiumUser::RecommendContent() const {
    std::cout << "Recommending content for: " << GetName()
              << " based on language: " << GetPreferredLanguage() << std::endl;
}