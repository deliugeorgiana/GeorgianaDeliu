#ifndef GUESTUSER_H
#define GUESTUSER_H

#include "User.h"

class GuestUser : public User {
public:
    // Constructor cu validare prin moștenire
    explicit GuestUser(const std::string& name, const std::string& preferredLanguage)
            : User(name, preferredLanguage) {}

    // Destructor virtual
    ~GuestUser() override = default;

    void DisplayProfile() const override;

    [[nodiscard]] std::shared_ptr<User> Clone() const override;

    // Getter pentru nume (suprascriere)
    [[nodiscard]] const std::string& GetName() const override { return name; }

};

#endif
