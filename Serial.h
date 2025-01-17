#ifndef SERIAL_H
#define SERIAL_H

#include "MediaItem.h"

// clasa derivata serial
class Serial : public MediaItem {
public:
    // constructor serial
    Serial([[maybe_unused]] [[maybe_unused]] std::string title, [[maybe_unused]] [[maybe_unused]] std::string description, float rating);

    //destructor
    ~Serial() override = default;

    // fcn virtuala rating
    [[nodiscard]] float GetRating() const override;

    //clone
    [[nodiscard]] std::shared_ptr<MediaItem> Clone() const override;
};

#endif
