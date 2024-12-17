#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

class AdminUser : public User {
public:
    explicit AdminUser(const std::string& name, const std::string& preferredLanguage)
            : User(name, preferredLanguage) {}

    ~AdminUser() override = default;

    void DisplayProfile() const override;

    static void ReportUser(const User& user);
};

#endif