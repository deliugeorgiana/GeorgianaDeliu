#ifndef MEDIA_FACTORY_H
#define MEDIA_FACTORY_H
#include "MediaItem.h"
#include "Movie.h"
#include "TVShow.h"
#include "Serial.h"
#include <memory>
class MediaFactory {
public:
    virtual ~MediaFactory() = default;
    virtual std::shared_ptr<MediaItem> createMedia(const std::string& title,
                                                   const std::string& description,
                                                   float rating) = 0;
};

class [[maybe_unused]] MovieFactory : public MediaFactory {
public:
    std::shared_ptr<MediaItem> createMedia(const std::string& title,
                                           const std::string& description,
                                           float rating) override {
        return std::make_shared<Movie>(title, description, rating);
    }
};

class [[maybe_unused]] TVShowFactory : public MediaFactory {
public:
    std::shared_ptr<MediaItem> createMedia(const std::string& title,
                                           const std::string& description,
                                           float rating) override {
        return std::make_shared<TVShow>(title, description, rating);
    }
};

class [[maybe_unused]] SerialFactory : public MediaFactory {
public:
    std::shared_ptr<MediaItem> createMedia(const std::string& title,
                                           const std::string& description,
                                           float rating) override {
        return std::make_shared<Serial>(title, description, rating);
    }
};

#endif
