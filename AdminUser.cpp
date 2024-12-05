#include "AdminUser.h"
#include <iostream>

void AdminUser::DisplayProfile() const {
    std::cout << "[Admin] Name: " << GetName()
              << ", Language: " << GetPreferredLanguage() << std::endl;
}

std::shared_ptr<User> AdminUser::Clone() const {
    return std::make_shared<AdminUser>(*this);
}
//acces prin getter
void AdminUser::ReportUser(const User& user) {
    std::cout << "Reporting user: " << user.GetName() << std::endl;
}