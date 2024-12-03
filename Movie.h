#ifndef MOVIE_H
#define MOVIE_H

#include "MediaItem.h"

//clasa deriv
class Movie : public MediaItem {
private:
    std::string description;
    float rating = 0.0f;
public:
    explicit Movie(const std::string& title) : MediaItem(title) {}
    //constructor
    Movie(std::string title, std::string description, float rating);

    //destructor
    ~Movie() override = default;

    // scoate ratingul
    [[nodiscard]] float GetRating() const override;

    // scoate tipul
    [[nodiscard]] std::string GetType() const override;




#endif
