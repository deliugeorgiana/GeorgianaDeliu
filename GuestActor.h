#ifndef GUEST_ACTOR_H
#define GUEST_ACTOR_H

#include "Actor.h"

//clasa derivata
class [[maybe_unused]] GuestActor : public Actor {
public:

    [[maybe_unused]] explicit GuestActor([[maybe_unused]] std::string name);

    ~GuestActor() override =default;
    //rolul principal
    [[nodiscard]] std::string GetMainRole() const override;

    // tipul rolului
    [[nodiscard]] std::string GetRoleType() const override;
};

#endif
