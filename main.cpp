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


int main() {
    // Creare obiecte
    std::shared_ptr<MediaItem> movie1 = std::make_shared<Movie>("Inception", "A mind-bending thriller.", 8.8f);
    std::shared_ptr<MediaItem> serial1 = std::make_shared<Serial>("Breaking Bad", "A chemistry teacher turned meth manufacturer.", 9.5f);
    std::shared_ptr<MediaItem> tvShow1 = std::make_shared<TVShow>("The Office", "A mockumentary about office life.", 8.9f);

    // Folosirea funcției GetItemCount
    std::cout << "Total Media Items created: " << MediaItem::GetItemCount() << std::endl;

    // Adăugarea unui gen
    MediaItem::AddGenre("Sci-Fi");
    MediaItem::AddGenre("Drama");
    MediaItem::AddGenre("Comedy");

    // Afișare informații folosind GetInfo
    std::cout << "Movie Info: " << movie1->GetInfo() << std::endl;
    std::cout << "Serial Info: " << serial1->GetInfo() << std::endl;
    std::cout << "TV Show Info: " << tvShow1->GetInfo() << std::endl;

    // Folosirea display pentru a afișa obiectele media
    movie1->display();
    serial1->display();
    tvShow1->display();

    // Afișare tipuri de media folosind GetType
    std::cout << "Movie type: " << movie1->GetType() << std::endl;
    std::cout << "Serial type: " << serial1->GetType() << std::endl;
    std::cout << "TV Show type: " << tvShow1->GetType() << std::endl;

    // Afișare genuri folosind GetGenres
    std::cout << "Genres for all MediaItems: ";
    const std::vector<std::string>& genres = MediaItem::GetGenres();
    for (const auto& genre : genres) {
        std::cout << genre << " ";
    }
    std::cout << std::endl;

    // Clonarea obiectelor media folosind Clone
    std::shared_ptr<MediaItem> clonedMovie = movie1->Clone();
    std::shared_ptr<MediaItem> clonedSerial = serial1->Clone();
    std::shared_ptr<MediaItem> clonedTVShow = tvShow1->Clone();

    // Afișarea clonelor
    std::cout << "Cloned Movie: " << *clonedMovie << std::endl;
    std::cout << "Cloned Serial: " << *clonedSerial << std::endl;
    std::cout << "Cloned TV Show: " << *clonedTVShow << std::endl;

    return 0;
}
