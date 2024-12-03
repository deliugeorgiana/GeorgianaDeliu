#ifndef MOVIE_H
#define MOVIE_H

#include "MediaItem.h"

//clasa deriv
class Movie : public MediaItem {
public:
    explicit Movie(const std::string& title) : MediaItem(title) {}
    //constructor
    Movie(std::string title, std::string description, float rating);

    //destructor
    virtual ~Movie() = default;

    // scoate ratingul
    [[nodiscard]] float GetRating() const override;

    // scoate tipul
    [[nodiscard]] std::string GetType() const override;

    //clona
    [[nodiscard]] std::shared_ptr<MediaItem> Clone() const override;
    };



#endif
