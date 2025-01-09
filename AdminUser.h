#ifndef ADMINUSER_H
#define ADMINUSER_H

#include "User.h"
#include <memory>

template <typename T>
class AdminUser : public User<T> {
public:
    explicit AdminUser(const std::string& name, const std::string& preferredLanguage)
            : User<T>(name, preferredLanguage) {}

    ~AdminUser() override = default;

    void DisplayProfile() const override {
        std::cout << "[Admin] Name: " << this->GetName()
                  << ", Language: " << this->GetPreferredLanguage() << std::endl;
    }

    static std::shared_ptr<AdminUser<T>> GetInstance(const std::string& name, const std::string& preferredLanguage) {
        if (!instance) {
            instance = std::make_shared<AdminUser<T>>(name, preferredLanguage);
        }
        return instance;
    }

    static void ReportUser(const User<T>& user) {
        std::cout << "Reporting user: " << user.GetName() << std::endl;
    }

private:
    static std::shared_ptr<AdminUser<T>> instance;
};

// Define the static member
template <typename T>
std::shared_ptr<AdminUser<T>> AdminUser<T>::instance = nullptr;

#endif
