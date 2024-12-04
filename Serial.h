#ifndef SERIAL_H
#define SERIAL_H

#include "MediaItem.h"

//Derived class
class Serial : public MediaItem {
public:
    // Constructor serial
    Serial([[maybe_unused]] std::string title, [[maybe_unused]] std::string description, float rating);

    //Destructor
    ~Serial() override = default;

    // Virtual rating function
    [[nodiscard]] float GetRating() const override;

    // Virtual type function
    [[nodiscard]] std::string GetType() const override;

    // Serial clone
    [[nodiscard]] std::shared_ptr<MediaItem> Clone() const override;
};

#endif
