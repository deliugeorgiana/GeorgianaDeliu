#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include "MediaItem.h"
#include "Movie.h"
#include "Serial.h"
#include "TVShow.h"
#include "User.h"
#include "AdminUser.h"
#include "GuestUser.h"
#include "PremiumUser.h"
#include "Category.h"
#include "ComedyCategory.h"
#include "DramaCategory.h"
#include "SciFiCategory.h"
#include "Actor.h"
#include "LeadActor.h"
#include "SupportingActor.h"
#include "GuestActor.h"
#include "Watchlist.h"
#include "FavoritesWatchlist.h"
#include "RecentWatchlist.h"
#include "RecommendationsWatchlist.h"
#include "WatchlistUtils.h"
#include "Observer.h"
#include "ConcreteObserver.h"
#include "Singleton.h"

#include <iostream>
#include <vector>
#include <memory>
#include "MediaItem.h"
#include "Movie.h" // Presupun că ai clase derivate precum Movie
#include "Serial.h"
#include "TVShow.h"

void DisplayMenu() {
    std::cout << "\n=== ShowRadar Menu ===\n";
    std::cout << "1. Add a Movie\n";
    std::cout << "2. Add a Serial\n";
    std::cout << "3. Add a TV Show\n";
    std::cout << "4. List All Media Items\n";
    std::cout << "5. Add a Genre\n";
    std::cout << "6. List All Genres\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

void AddMovie(std::vector<std::shared_ptr<MediaItem>>& mediaItems) {
    std::string title, description;
    float rating;

    std::cout << "Enter Movie Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter Movie Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter Movie Rating: ";
    std::cin >> rating;

    mediaItems.push_back(std::make_shared<Movie>(title, description, rating));
    std::cout << "Movie added successfully!\n";
}

void AddSerial(std::vector<std::shared_ptr<MediaItem>>& mediaItems) {
    std::string title, description;
    float rating;

    std::cout << "Enter Serial Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter Serial Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter Serial Rating: ";
    std::cin >> rating;

    mediaItems.push_back(std::make_shared<Serial>(title, description, rating));
    std::cout << "Serial added successfully!\n";
}

void AddTVShow(std::vector<std::shared_ptr<MediaItem>>& mediaItems) {
    std::string title, description;
    float rating;

    std::cout << "Enter TV Show Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Enter TV Show Description: ";
    std::getline(std::cin, description);

    std::cout << "Enter TV Show Rating: ";
    std::cin >> rating;

    mediaItems.push_back(std::make_shared<TVShow>(title, description, rating));
    std::cout << "TV Show added successfully!\n";
}

void ListMediaItems(const std::vector<std::shared_ptr<MediaItem>>& mediaItems) {
    if (mediaItems.empty()) {
        std::cout << "No media items available.\n";
        return;
    }

    std::cout << "\n=== Media Items ===\n";
    for (const auto& item : mediaItems) {
        std::cout << *item << "\n";
    }
}

void AddGenre() {
    std::string genre;
    std::cout << "Enter Genre: ";
    std::cin.ignore();
    std::getline(std::cin, genre);

    MediaItem::AddGenre(genre);
    std::cout << "Genre added successfully!\n";
}

void ListGenres() {
    const auto& genres = MediaItem::GetGenres();
    if (genres.empty()) {
        std::cout << "No genres available.\n";
        return;
    }

    std::cout << "\n=== Available Genres ===\n";
    for (const auto& genre : genres) {
        std::cout << genre << "\n";
    }
}

int main() {
    std::vector<std::shared_ptr<MediaItem>> mediaItems;
    int choice;

    do {
        DisplayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                AddMovie(mediaItems);
                break;
            case 2:
                AddSerial(mediaItems);
                break;
            case 3:
                AddTVShow(mediaItems);
                break;
            case 4:
                ListMediaItems(mediaItems);
                break;
            case 5:
                AddGenre();
                break;
            case 6:
                ListGenres();
                break;
            case 0:
                std::cout << "Exiting... Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
