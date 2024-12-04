#ifndef MEDIA_ITEM_H
#define MEDIA_ITEM_H

#include <string>
#include <iostream>
#include <memory>

class MediaItem {
protected:
    std::string title;
    std::string description;
    float rating= 0.0f;

public:
    // constructor explicit titlu
    explicit MediaItem(std::string title);

// constructor titlu, descriere, rating
    MediaItem(std::string title, std::string description, float rating);

// destructor virtual, permite moștenirea
    virtual ~MediaItem() = default;

    void display() const {
        std::cout << "Title: " << title << ", Genre: " << description << ", Rating: " << rating << std::endl;
    }

//functie virtuala pura pt rating
    [[nodiscard]] virtual float GetRating() const = 0;

// functie virtuala pura pt tipul de media
    [[nodiscard]] virtual std::string GetType() const = 0;

// functe virtuala pura pt a scoate info despre obiect
    [[nodiscard]] virtual std::string GetInfo() const;

// functie virt pura pt copierea/clonarea unui obiect
    [[nodiscard]] virtual std::shared_ptr<MediaItem> Clone() const = 0;

    [[nodiscard]] const std::string& GetTitle() const;

    [[nodiscard]] const std::string& GetDescription() const;


// suprascrierea operatorului, incarcarea unui obiect
    friend std::ostream &operator<<(std::ostream &os, const MediaItem &media);
};

#endif


