#ifndef GUESTUSER_H
#define GUESTUSER_H

#include "User.h"

template <typename T>
class GuestUser : public User<T> {
public:
    explicit GuestUser(const std::string& name, const std::string& preferredLanguage)
            : User<T>(name, preferredLanguage) {}

    ~GuestUser() override = default;

    void DisplayProfile() const override {
        std::cout << "[Guest] Name: " << this->GetName()
                  << ", Language: " << this->GetPreferredLanguage() << std::endl;
    }
};

#endif // GUESTUSER_H
