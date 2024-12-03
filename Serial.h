#ifndef SERIAL_H
#define SERIAL_H

#include "MediaItem.h"

// clasa derivata serial
class Serial : public MediaItem {
private:
    std::string title;
    std::string description;
    float rating= 0.0f;
public:
    // constructor serial
    Serial(std::string title, std::string description, float rating);

    //destructor
    ~Serial() override = default;

    // fcn virtuala rating
    [[nodiscard]] float GetRating() const override;

    // fcn virtuala tip
    [[nodiscard]] std::string GetType() const override;

    // clona obiect serial
    [[nodiscard]] std::shared_ptr<MediaItem> Clone() const override;
};

#endif
