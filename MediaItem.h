#ifndef MEDIA_ITEM_H
#define MEDIA_ITEM_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>

class MediaItem {
protected:
    std::string title;
    std::string description;
    float rating = 0.0f;

    static int itemCount;
    static std::vector<std::string> genres;

public:
    // Explicit constructor title
    explicit MediaItem(std::string title);

    // Constructor for title, description, ratinf
    MediaItem(std::string title, std::string description, float rating);

    // Virtual destructor
    virtual ~MediaItem() = default;

    void display() const {
        std::cout << "Title: " << title << ", Genre: " << description << ", Rating: " << rating << std::endl;
    }

    // Virtual function fot rating
    [[nodiscard]] virtual float GetRating() const = 0;

    // Virtual function for type
    [[nodiscard]] virtual std::string GetType() const = 0;

    // Virtual function for info
    [[nodiscard]] virtual std::string GetInfo() const;

    // Virtul fcn clone
    [[nodiscard]] virtual std::shared_ptr<MediaItem> Clone() const = 0;

    // getter title
    [[nodiscard]] const std::string& GetTitle() const;

    // getter description
    [[nodiscard]] const std::string& GetDescription() const;

    // suprascrierea operatorului, incarcarea unui obiect
    friend std::ostream &operator<<(std::ostream &os, const MediaItem &media);

    static int GetItemCount();
    static void AddGenre(const std::string& genre);
    static const std::vector<std::string>& GetGenres();
};

#endif