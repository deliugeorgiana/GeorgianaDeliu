#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"

class PremiumUser : public User {
public:
    explicit PremiumUser(const std::string& name, std::string preferredLanguage)
            : User(name, preferredLanguage) { // moves the copies to the base class
        std::cout << "Creating PremiumUser with name: " << name
                  << " and preferred language: " << preferredLanguage << std::endl;

        if (preferredLanguage == "English") {
            std::cout << "PremiumUser prefers English." << std::endl;
        }
    }

    // Destructor
    ~PremiumUser() override = default;

    void DisplayProfile() const override;

    [[nodiscard]] std::shared_ptr<User> Clone() const override;

    void RecommendContent() const;
};

#endif
