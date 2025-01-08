#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <vector>
#include <memory>
#include "MediaItem.h"

class Actor {
protected:
    std::string name;
    std::vector<std::shared_ptr<MediaItem>> filmography;

public:

    explicit Actor(std::string name);

    // destr virtual
    virtual ~Actor() = default;
    // af filmele din lista actorului
    void DisplayFilms() const;

    // adds a movie
    void AddFilm(const std::shared_ptr<MediaItem>& item);

    //metoda virtuala pt rolul primcipal
    [[nodiscard]] virtual std::string GetMainRole() const;

    // sa afle tipul de rol
    [[nodiscard]] virtual std::string GetRoleType() const = 0;

    // numele actorului
    [[nodiscard]] const std::string& GetName() const;

    friend std::ostream& operator<<(std::ostream& os, const Actor& actor);
};

#endif
