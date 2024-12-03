#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"

class PremiumUser : public User {
public:
    explicit PremiumUser(std::string name, std::string preferredLanguage)
            : User(std::move(name), std::move(preferredLanguage)) {
        std::cout << "Creating PremiumUser with name: " << name
                  << " and preferred language: " << preferredLanguage << std::endl;

        if (preferredLanguage == "English") {
            std::cout << "PremiumUser prefers English." << std::endl;
        }
    }

    //destructor
    ~PremiumUser() override = default;

    void DisplayProfile() const override;

    [[nodiscard]] std::shared_ptr<User> Clone() const override;

    void RecommendContent() const;
};

#endif
