#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H

#include "User.h"

class PremiumUser : public User {
public:
    explicit PremiumUser(std::string name, std::string preferredLanguage)
            : User(std::move(name), std::move(preferredLanguage)) {
        std::string nameCopy = std::move(name);
        std::string languageCopy = std::move(preferredLanguage);

        std::cout << "Creating PremiumUser with name: " << nameCopy
                  << " and preferred language: " << languageCopy << std::endl;

        if (languageCopy == "English") {
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
