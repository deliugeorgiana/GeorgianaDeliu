#ifndef COMMAND_H
#define COMMAND_H
#include "MediaItem.h"
#include "MediaFactory.h"
#include <iostream>
#include <utility>
class Command {
public:
    virtual ~Command() = default;

    [[maybe_unused]] virtual void execute() = 0;
};

class [[maybe_unused]] AddMediaCommand : public Command {
private:
    std::vector<std::shared_ptr<MediaItem>>& items;
    std::shared_ptr<MediaFactory> factory;

public:
    [[maybe_unused]] AddMediaCommand(std::vector<std::shared_ptr<MediaItem>>& itemsList,
                    std::shared_ptr<MediaFactory> mediaFactory)
            : items(itemsList), factory(std::move(mediaFactory)) {}

    void execute() override {
        std::string title, description;
        float rating;

        std::cout << "Enter title: ";
        std::cin.ignore();
        getline(std::cin, title);
        std::cout << "Enter description: ";
        getline(std::cin, description);
        std::cout << "Enter rating: ";
        std::cin >> rating;

        items.push_back(factory->createMedia(title, description, rating));
    }
};

class [[maybe_unused]] ListItemsCommand : public Command {
private:
    const std::vector<std::shared_ptr<MediaItem>>& items;

public:
    [[maybe_unused]] explicit ListItemsCommand(const std::vector<std::shared_ptr<MediaItem>>& itemsList)
            : items(itemsList) {}

    void execute() override {
        if (!items.empty()) {
            std::cout << "Listing all items:\n";
            for (const auto& item : items) {
                std::cout << *item << "\n";
            }
        } else {
            std::cout << "No items available to list.\n";
        }
    }
};

#endif