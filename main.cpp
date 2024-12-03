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

class MediaException : public std::runtime_error {
public:
    explicit MediaException(const std::string& message)
            : std::runtime_error("MediaException: " + message) {}
};

class UserException : public std::runtime_error {
public:
    explicit UserException(const std::string& message)
            : std::runtime_error("UserException: " + message) {}
};

class CategoryException : public std::runtime_error {
public:
    explicit CategoryException(const std::string& message)
            : std::runtime_error("CategoryException: " + message) {}
};

class ActorException : public std::exception {
    std::string message;
public:
    explicit ActorException(std::string  msg) : message(std::move(msg)) {}
    [[nodiscard]] const char* what() const noexcept override { return message.c_str(); }
};

void DisplayActors(const std::vector<std::shared_ptr<Actor>>& actors) {
    for (const auto& actor : actors) {
        std::cout << actor->GetName() << std::endl;
    }
}

class WatchlistException : public std::exception {
private:
    std::string message;

public:
    explicit WatchlistException(std::string msg) : message(std::move(msg)) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};



int main() {
    //////////MEDIAITEM
    std::cout<<"\nMEDIAITEM\n";

    try {
        // situatie cu exceptie
        throw MediaException("Exceptie manuala im main");
    } catch (const MediaException& e) {
        std::cerr << "Caught MediaException: " << e.what() << std::endl;
    }

    try {
        //creare el MediaItem
        std::vector<std::shared_ptr<MediaItem>> mediaItems;

        // obiecte
        auto inception = std::make_shared<Movie>("Inception", "A mind-bending thriller", 9.0f);
        auto breakingBad = std::make_shared<TVShow>("Breaking Bad", "A teacher turns to crime", 9.5f);
        auto friends = std::make_shared<Serial>("Friends", "A group of friends in NYC", 8.5f);

        mediaItems.push_back(inception);
        mediaItems.push_back(breakingBad);
        mediaItems.push_back(friends);

        std::cout << "Media Items created successfully.\n";

        // functii virtuala
        std::cout << "\nDisplaying Media Info using overloaded << operator:\n";
        for (const auto& item : mediaItems) {
            std::cout << "Type: " << item->GetType() << "\n" << *item << "\n";
        }

        // utilizare getinfo
        std::cout << "\nDisplaying Media Information using GetInfo:\n";
        for (const auto& item : mediaItems) {
            std::cout << item->GetInfo() << "\n";
        }

        // obiecte in plus
        auto darkKnight = std::make_shared<Movie>("The Dark Knight", "A superhero faces chaos in Gotham", 9.1f);
        auto theOffice = std::make_shared<Serial>("The Office", "Everyday office antics", 8.8f);

        mediaItems.push_back(darkKnight);
        mediaItems.push_back(theOffice);

        std::cout << "\nAdded new Media Items:\n";
        for (const auto& item : mediaItems) {
            std::cout << item->GetTitle() << " - " << item->GetType() << "\n";
        }

        // exceptii
        std::cout << "\nTesting exception handling:\n";
        try {
            auto invalidMedia = std::make_shared<Movie>("Invalid Movie", "No description", -5.0f);
            mediaItems.push_back(invalidMedia);
        } catch (const MediaException& e) {
            std::cerr << e.what() << "\n";
        }

        // dynamic_cast
        std::cout << "\nUsing dynamic_cast to find specific MediaItems:\n";
        for (const auto& item : mediaItems) {
            if (auto movie = dynamic_cast<Movie*>(item.get())) {
                std::cout << "Found a movie: " << movie->GetTitle() << "\n";
            } else if (auto tvShow = dynamic_cast<TVShow*>(item.get())) {
                std::cout << "Found a TV Show: " << tvShow->GetTitle() << "\n";
            } else if (auto serial = dynamic_cast<Serial*>(item.get())) {
                std::cout << "Found a Serial: " << serial->GetTitle() << "\n";
            }
        }

        // functii Clone
        std::cout << "\nCloning media items:\n";
        auto clonedItem = mediaItems[0]->Clone();
        std::cout << "Cloned item: " << *clonedItem << "\n";

        // ==================== STL Sorting ====================
        std::cout << "\nSorting MediaItems by rating:\n";
        std::sort(mediaItems.begin(), mediaItems.end(), [](const auto& a, const auto& b) {
            return a->GetRating() > b->GetRating();
        });

        for (const auto& item : mediaItems) {
            std::cout << item->GetTitle() << " - Rating: " << item->GetRating() << "\n";
        }

        // item specific
        std::cout << "\nSearching for 'Friends' in MediaItems:\n";
        auto it = std::find_if(mediaItems.begin(), mediaItems.end(), [](const auto& item) {
            return item->GetTitle() == "Friends";
        });

        if (it != mediaItems.end()) {
            std::cout << "Found: " << **it << "\n";
        } else {
            std::cout << "'Friends' not found.\n";
        }

        // afisare
        std::cout << "\nDisplaying all MediaItems after all operations:\n";
        for (const auto& item : mediaItems) {
            std::cout << item->GetInfo() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }


    //////////////////////////USER
std::cout<<"\nUSER\n";
    try {
        // smart pointers
        std::vector<std::shared_ptr<User>> users;

        auto adminUser = std::make_shared<AdminUser>("Alice", "English");
        auto guestUser = std::make_shared<GuestUser>("Bob", "French");
        auto premiumUser = std::make_shared<PremiumUser>("Charlie", "English");

        // utilizatori
        users.push_back(adminUser);
        users.push_back(guestUser);
        users.push_back(premiumUser);

        // obiecte pt favorite
        auto mediaItem1 = std::make_shared<Movie>("Inception", "A mind-bending thriller", 9.0f);
        auto mediaItem2 = std::make_shared<TVShow>("Breaking Bad", "A teacher turns to crime", 9.5f);
        auto mediaItem3 = std::make_shared<Serial>("Friends", "A group of friends in NYC", 8.5f);

        //adauga la favorite
        adminUser->AddToFavorites(mediaItem1);
        guestUser->AddToFavorites(mediaItem2);
        premiumUser->AddToFavorites(mediaItem3);
        premiumUser->AddToFavorites(mediaItem1);

        // afisare profil utilizatori cu fcn virt
        std::cout << "\nDisplaying all profiles:\n";
        for (const auto& user : users) {
            user->DisplayProfile();
            std::cout << "Number of favorites: " << user->FavoriteCount() << "\n";
        }

        std::cout << "\nAdmin reporting a user:\n";
        AdminUser::ReportUser(*guestUser);  // Apelăm funcția statică

        // recomandare continut premium user
        std::cout << "\nPremium user recommending content:\n";
        premiumUser->RecommendContent();

        // dynamic_cast
        std::cout << "\nUsing dynamic_cast to identify user types:\n";
        for (const auto& user : users) {
            if (auto admin = dynamic_cast<AdminUser*>(user.get())) {
                std::cout << "Found Admin: " << admin->GetName() << std::endl;
            } else if (auto guest = dynamic_cast<GuestUser*>(user.get())) {
                std::cout << "Found Guest: " << guest->GetName() << std::endl;
            } else if (auto premium = dynamic_cast<PremiumUser*>(user.get())) {
                std::cout << "Found Premium: " << premium->GetName() << std::endl;
            }
        }

        // throw si catch a unei exceptii
        std::cout << "\nTesting exception handling:\n";
        try {
            // ultilizator invalid
            auto invalidUser = std::make_shared<PremiumUser>("InvalidUser", "");
            users.push_back(invalidUser);  // il bagam in lista
            throw UserException("Invalid user created with no preferred language.");
        } catch (const UserException& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        // testare clone
        std::cout << "\nTesting Clone functionality:\n";
        auto clonedUser = adminUser->Clone();
        std::cout << "Cloned user: " << *clonedUser << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

////////////////////////CATEGORY
std::cout<<"CATEGORY";

    try {
        // colectie categorii cu pointeri smart
        std::vector<std::shared_ptr<Category>> categories;

        // categorii in vect
        categories.push_back(std::make_shared<ComedyCategory>("Comedy Central"));
        categories.push_back(std::make_shared<DramaCategory>("Heartfelt Dramas"));
        categories.push_back(std::make_shared<SciFiCategory>("Future Visions"));

        // folosire fcn virtuale
        std::cout << "\nDisplaying all categories:\n";
        for (const auto& category : categories) {
            std::cout << *category << std::endl;
        }

        // clonare
        std::cout << "\nCloning categories:\n";
        std::vector<std::shared_ptr<Category>> clonedCategories;
        for (const auto& category : categories) {
            clonedCategories.push_back(category->Clone());
            std::cout << *clonedCategories.back() << std::endl;
        }

        // dynamic_cast
        std::cout << "\nUsing dynamic_cast to identify category types:\n";
        for (const auto& category : categories) {
            if (auto comedy = dynamic_cast<ComedyCategory*>(category.get())) {
                std::cout << "Found Comedy category: " << comedy->GetCategoryName() << std::endl;
            } else if (auto drama = dynamic_cast<DramaCategory*>(category.get())) {
                std::cout << "Found Drama category: " << drama->GetCategoryName() << std::endl;
            } else if (auto sciFi = dynamic_cast<SciFiCategory*>(category.get())) {
                std::cout << "Found Sci-Fi category: " << sciFi->GetCategoryName() << std::endl;
            }
        }

        // testare exceptii
        std::cout << "\nTesting exception handling:\n";
        try {
            // Aruncăm o excepție dacă se încearcă crearea unei categorii cu un nume gol
            auto invalidCategory = std::make_shared<ComedyCategory>("");
            categories.push_back(invalidCategory);  // Adăugăm în vector
            throw CategoryException("Invalid category name: empty string.");
        } catch (const CategoryException& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        // testate clone
        std::cout << "\nTesting Clone with invalid category:\n";
        try {
            auto invalidCategoryClone = std::make_shared<DramaCategory>("");
            categories.push_back(invalidCategoryClone);
            std::cout << "Cloned invalid category: " << *invalidCategoryClone->Clone() << std::endl;
        } catch (const CategoryException& e) {
            std::cerr << "Caught exception while cloning: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

/////////////////////////ACTORI
std::cout<<"ACTORI";
    try {
        // pointeru ot filme
        std::shared_ptr<MediaItem> movie1 = std::make_shared<Movie>("Interstellar");
        std::shared_ptr<MediaItem> movie2 = std::make_shared<Movie>("The Dark Knight");
        std::shared_ptr<MediaItem> movie3 = std::make_shared<Movie>("Inception");

       //af ce a gasit
        movie1->display();
        movie2->display();
        movie3->display();

        //se creaza actori
        auto leadActor = std::make_shared<LeadActor>("Leonardo DiCaprio");
        auto supportingActor = std::make_shared<SupportingActor>("Joseph Gordon-Levitt");
        auto guestActor = std::make_shared<GuestActor>("Tom Hardy");

        // asociere film-actor
        leadActor->AddFilm(movie1);
        leadActor->AddFilm(movie2);
        supportingActor->AddFilm(movie2);
        supportingActor->AddFilm(movie3);
        guestActor->AddFilm(movie3);

        // tets invalid
        auto invalidActor = std::make_shared<LeadActor>("");
        if (invalidActor->GetName().empty()) {
            throw ActorException("Actor name cannot be empty!");
        }

        // actori bagati in vector
        std::vector<std::shared_ptr<Actor>> actors = {leadActor, supportingActor, guestActor};

        // profilul actorilor
        std::cout << "\nActor Profiles:\n";
        DisplayActors(actors);

        // apeluri virtuale demonstrate
        std::cout << "\nDemonstration of Virtual Function Calls:\n";
        for (const auto& actor : actors) {
            std::cout << "Role Type: " << actor->GetRoleType()
                      << ", Main Role: " << actor->GetMainRole() << "\n";
        }

        // test clonare
        std::cout << "\nTesting Clone Function:\n";
        auto clonedLeadActor = leadActor->Clone();
        std::cout << "Cloned Lead Actor: " << *clonedLeadActor << "\n";

        // testeaza filme asociate cu actori
        std::cout << "\nFilms Associated with Actors:\n";
        for (const auto& actor : actors) {
            std::cout << "Actor: " << actor->GetName() << ", Films: ";
            actor->DisplayFilms();
        }

        // << pentru af actorilor
        std::cout << "\nUsing operator<< to display actors:\n";
        for (const auto& actor : actors) {
            std::cout << *actor << "\n";
        }

        // dyn_cast
        std::cout << "\nTesting Polymorphism with dynamic_cast:\n";
        for (const auto& actor : actors) {
            if (auto lead = std::dynamic_pointer_cast<LeadActor>(actor)) {
                std::cout << "Lead Actor Detected: " << lead->GetName() << "\n";
            } else if (auto support = std::dynamic_pointer_cast<SupportingActor>(actor)) {
                std::cout << "Supporting Actor Detected: " << support->GetName() << "\n";
            } else if (auto guest = std::dynamic_pointer_cast<GuestActor>(actor)) {
                std::cout << "Guest Actor Detected: " << guest->GetName() << "\n";
            }
        }

    } catch (const ActorException& e) {
        std::cerr << "ActorException caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "General exception caught: " << e.what() << std::endl;
    }
    auto leadActor = std::make_shared<LeadActor>("Robert Downey Jr.");
    auto supportingActor = std::make_shared<SupportingActor>("Chris Evans");
    auto guestActor = std::make_shared<GuestActor>("Scarlett Johansson");

    leadActor->AddFilm(std::make_shared<Movie>("Iron Man"));
    supportingActor->AddFilm(std::make_shared<Movie>("Avengers"));
    guestActor->AddFilm(std::make_shared<Movie>("Black Widow"));

    std::cout << "Lead Actor: " << *leadActor << std::endl;
    std::cout << "Supporting Actor: " << *supportingActor << std::endl;
    std::cout << "Guest Actor: " << *guestActor << std::endl;


    /////////////////////////////////WATCHLIST
    std::cout<<"\nWATCLIST\n";
    try {
        // facem obiecte
        std::shared_ptr<MediaItem> movie1 = std::make_shared<Movie>("Inception");
        std::shared_ptr<MediaItem> movie2 = std::make_shared<Movie>("The Matrix");
        std::shared_ptr<MediaItem> movie3 = std::make_shared<Movie>("Interstellar");


        // actori prin mosteniri si fcn virt
        std::shared_ptr<Actor> leadActorPtr = std::make_shared<LeadActor>("Robert Downey");
        std::shared_ptr<Actor> supportingActorPtr = std::make_shared<SupportingActor>("Chris Evans");
        std::shared_ptr<Actor> guestActorPtr = std::make_shared<GuestActor>("Scarlett Johansson");

        // adaugam filme
        leadActor->AddFilm(movie1);
        supportingActor->AddFilm(movie2);
        guestActor->AddFilm(movie3);

        // verificam ap fcn
        std::vector<std::shared_ptr<Actor>> actors = {leadActor, supportingActor, guestActor};
        for (const auto& actor : actors) {
            std::cout << *actor << ", Role: " << actor->GetRoleType() << ", Main Film: " << actor->GetMainRole() << '\n';
        }

        // facem liste pt useri
        std::unique_ptr<Watchlist> favorites = std::make_unique<FavoritesWatchlist>("User1");
        std::unique_ptr<Watchlist> recent = std::make_unique<RecentWatchlist>("User2");
        std::unique_ptr<Watchlist> recommendations = std::make_unique<RecommendationsWatchlist>("User3");

        // bagam filme
        favorites->AddToWatchlist(movie1);
        favorites->AddToWatchlist(movie2);

        recent->AddToWatchlist(movie3);

        recommendations->AddToWatchlist(movie1);
        recommendations->AddToWatchlist(movie3);

        // afisare
        std::cout << "\n--- Displaying Watchlists ---\n";
        favorites->DisplayWatchlist();
        recent->DisplayWatchlist();
        recommendations->DisplayWatchlist();

        // dyn_cast
        auto specificWatchlist = dynamic_cast<FavoritesWatchlist*>(favorites.get());
        if (specificWatchlist) {
            std::cout << "Dynamic cast to FavoritesWatchlist successful.\n";
        } else {
            throw WatchlistException("Dynamic cast to FavoritesWatchlist failed.");
        }

        // exceptii
        std::cout << "\n--- Testing Exceptions ---\n";
        recommendations->RemoveFromWatchlist(movie2); // Acest film nu există în listă
    } catch (const WatchlistException& e) {
        std::cerr << "WatchlistException caught: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
    }


    return 0;
}




