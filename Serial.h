#ifndef SERIAL_H
#define SERIAL_H

#include "MediaItem.h"

// clasa derivata serial
class Serial : public MediaItem {
public:
    // constructor serial
    Serial(std::string title, std::string description, float rating);

    //destructor
    virtual ~Serial() = default;

    // fcn virtuala rating
    [[nodiscard]] float GetRating() const override;

    // fcn virtuala tip
    [[nodiscard]] std::string GetType() const override;

    // clona obiect serial
    [[nodiscard]] std::shared_ptr<MediaItem> Clone() const override;
};

#endif
