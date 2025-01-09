#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"

template <typename T>
class PremiumUser : public User<T> {
public:
    explicit PremiumUser(const std::string& name, const std::string& preferredLanguage)
            : User<T>(name, preferredLanguage) { // transfering through constant reference
        std::cout << "Creating PremiumUser with name: " << name
                  << " and preferred language: " << preferredLanguage << std::endl;

        if (preferredLanguage == "English") {
            std::cout << "PremiumUser prefers English." << std::endl;
        }
    }

    ~PremiumUser() override = default;

    void DisplayProfile() const override {
        std::cout << "[Premium] Name: " << this->GetName()
                  << ", Language: " << this->GetPreferredLanguage() << std::endl;
    }

    void RecommendContent() const {
        std::cout << "Recommending content for: " << this->GetName()
                  << " based on language: " << this->GetPreferredLanguage() << std::endl;
    }
};

#endif
