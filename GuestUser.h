#ifndef GUESTUSER_H
#define GUESTUSER_H

#include "User.h"

class GuestUser : public User {
public:
    explicit GuestUser(const std::string& name, const std::string& preferredLanguage)
            : User(name, preferredLanguage) {}

    ~GuestUser() override = default;

    void DisplayProfile() const override;

};

#endif // GUESTUSER_H
