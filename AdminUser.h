#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"

class AdminUser : public User {
public:
    explicit AdminUser(const std::string& name, const std::string& preferredLanguage)
            : User(name, preferredLanguage) {}

    void DisplayProfile() const override;  // Declarație
    [[nodiscard]] std::shared_ptr<User> Clone() const override; // Declarație

    static void ReportUser(const User& user); // Static, deoarece nu folosește membri
};

#endif // ADMINUSER_H
