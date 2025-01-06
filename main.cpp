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
//Exceptions

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

class [[maybe_unused]] WatchlistException : public std::exception {
private:
    std::string message;

public:
    [[maybe_unused]] explicit WatchlistException(std::string msg) : message(std::move(msg)) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};



int main() {
    //////////MEDIAITEM
    std::cout << "\nMEDIAITEM\n";

    try {
        // situatie cu exceptie
        throw MediaException("Exceptie manuala im main");
    } catch (const MediaException &e) {
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
        for (const auto &item: mediaItems) {
            std::cout << "Type: " << item->GetType() << "\n" << *item << "\n";
        }

        // utilizare getinfo
        std::cout << "\nDisplaying Media Information using GetInfo:\n";
        for (const auto &item: mediaItems) {
            std::cout << item->GetInfo() << "\n";
        }

        // obiecte in plus
        auto darkKnight = std::make_shared<Movie>("The Dark Knight", "A superhero faces chaos in Gotham", 9.1f);
        auto theOffice = std::make_shared<Serial>("The Office", "Everyday office antics", 8.8f);

        mediaItems.push_back(darkKnight);
        mediaItems.push_back(theOffice);

        std::cout << "\nAdded new Media Items:\n";
        for (const auto &item: mediaItems) {
            std::cout << item->GetTitle() << " - " << item->GetType() << "\n";
        }

        // exceptii
        std::cout << "\nTesting exception handling:\n";
        try {
            auto invalidMedia = std::make_shared<Movie>("Invalid Movie", "No description", -5.0f);
            mediaItems.push_back(invalidMedia);
        } catch (const MediaException &e) {
            std::cerr << e.what() << "\n";
        }

        // dynamic_cast
        std::cout << "\nUsing dynamic_cast to find specific MediaItems:\n";
        for (const auto &item: mediaItems) {
            if (auto const *movie = dynamic_cast<const Movie *>(item.get())) { // Pointer const
                std::cout << "Found a movie: " << movie->GetTitle() << "\n";
            } else if (auto const *tvShow = dynamic_cast<const TVShow *>(item.get())) { // Pointer const
                std::cout << "Found a TV Show: " << tvShow->GetTitle() << "\n";
            } else if (auto const *serial = dynamic_cast<const Serial *>(item.get())) { // Pointer const
                std::cout << "Found a Serial: " << serial->GetTitle() << "\n";
            }
        }

        //clone
        std::cout << "\nTesting Clone functionality:\n";
        auto clonedMovie = inception->Clone();
        std::cout << "Cloned Movie: " << *clonedMovie << std::endl;

        auto clonedSerial = friends->Clone();
        std::cout << "Cloned Serial: " << *clonedSerial << std::endl;

        // item specific
        std::cout << "\nSearching for 'Friends' in MediaItems:\n";
        auto it = std::find_if(mediaItems.begin(), mediaItems.end(), [](const auto &item) {
            return item->GetTitle() == "Friends";
        });

        if (it != mediaItems.end()) {
            std::cout << "Found: " << **it << "\n";
        } else {
            std::cout << "'Friends' not found.\n";
        }

        // afisare
        std::cout << "\nDisplaying all MediaItems after all operations:\n";
        for (const auto &item: mediaItems) {
            std::cout << item->GetInfo() << "\n";
        }

    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

    //static
    MediaItem::AddGenre("Action");
    MediaItem::AddGenre("Drama");
    MediaItem::AddGenre("Sci-Fi");
    MediaItem::AddGenre("Thriller");

    // Afișăm lista de genuri
    std::cout << "Available genres:\n";
    for (const auto &genre: MediaItem::GetGenres()) {
        std::cout << "- " << genre << '\n';
    }

    // Creăm obiecte de tip Movie
    auto item1 = std::make_shared<Movie>("Inception", "Sci-Fi/Thriller", 9.0f);
    auto item2 = std::make_shared<Movie>("The Godfather", "Crime/Drama", 9.5f);

    // Afișăm informațiile despre obiecte
    std::cout << "\nMovies:\n";
    std::cout << item1->GetInfo() << std::endl;
    std::cout << item2->GetInfo() << std::endl;

    // Afișăm numărul total de obiecte MediaItem
    std::cout << "\nTotal Media Items: " << MediaItem::GetItemCount() << std::endl;

    // Ștergem un obiect pentru a verifica decrementarea contorului
    item1.reset();

    std::cout << "Total Media Items after deleting one: " << MediaItem::GetItemCount() << std::endl;




    //////////////////////////USER
    std::cout << "\nUSER\n";
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
        for (const auto &user: users) {
            user->DisplayProfile();
            std::cout << "Number of favorites: " << user->FavoriteCount() << "\n";
        }

        // Raportarea unui utilizator
        std::cout << "\nAdmin reporting a user:\n";
        AdminUser::ReportUser(*guestUser);


        // Crearea unui alt admin pentru a demonstra utilizarea lui adminCount
        auto anotherAdmin = std::make_shared<AdminUser>("Dave", "German");
        users.push_back(anotherAdmin);


        // recomandare continut premium user
        std::cout << "\nPremium user recommending content:\n";
        premiumUser->RecommendContent();

        // dynamic_cast
        std::cout << "\nUsing dynamic_cast to identify user types:\n";
        for (const auto &user: users) {
            if (auto const *admin = dynamic_cast<const AdminUser *>(user.get())) {
                std::cout << "Found Admin: " << admin->GetName() << std::endl;
            } else if (auto const *guest = dynamic_cast<const GuestUser *>(user.get())) {
                std::cout << "Found Guest: " << guest->GetName() << std::endl;
            } else if (auto const *premium = dynamic_cast<const PremiumUser *>(user.get())) {
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
        } catch (const UserException &e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

////////////////////////CATEGORY
    std::cout << "CATEGORY";

    try {
        // colectie categorii cu pointeri smart
        std::vector<std::shared_ptr<Category>> categories;

        // categorii in vect
        categories.push_back(std::make_shared<ComedyCategory>("Comedy Central"));
        categories.push_back(std::make_shared<DramaCategory>("Heartfelt Dramas"));
        categories.push_back(std::make_shared<SciFiCategory>("Future Visions"));

        // folosire fcn virtuale
        std::cout << "\nDisplaying all categories:\n";
        for (const auto &category: categories) {
            std::cout << *category << std::endl;
        }


        // dynamic_cast
        std::cout << "\nUsing dynamic_cast to identify category types:\n";
        for (const auto &category: categories) {
            if (auto const *comedy = dynamic_cast<const ComedyCategory *>(category.get())) {
                std::cout << "Found Comedy category: " << comedy->GetCategoryName() << std::endl;
            } else if (auto const *drama = dynamic_cast<const DramaCategory *>(category.get())) {
                std::cout << "Found Drama category: " << drama->GetCategoryName() << std::endl;
            } else if (auto const *sciFi = dynamic_cast<const SciFiCategory *>(category.get())) {
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
        } catch (const CategoryException &e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        // testate clone
        std::cout << "\nTesting Clone with invalid category:\n";
        try {
            auto invalidCategoryClone = std::make_shared<DramaCategory>("");
            categories.push_back(invalidCategoryClone);
        } catch (const CategoryException &e) {
            std::cerr << "Caught exception while cloning: " << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << "\n";
    }

/////////////////////////ACTORI
    std::cout << "ACTORI";
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
        for (const auto &actor: actors) {
            std::cout << "Role Type: " << actor->GetRoleType()
                      << ", Main Role: " << actor->GetMainRole() << "\n";
        }


        // testeaza filme asociate cu actori
        std::cout << "\nFilms Associated with Actors:\n";
        for (const auto &actor: actors) {
            std::cout << "Actor: " << actor->GetName() << ", Films: ";
            actor->DisplayFilms();
        }

        // << pentru af actorilor
        std::cout << "\nUsing operator<< to display actors:\n";
        for (const auto &actor: actors) {
            std::cout << *actor << "\n";
        }

        // dyn_cast
        std::cout << "\nTesting Polymorphism with dynamic_cast:\n";
        for (const auto &actor: actors) {
            if (auto const lead = std::dynamic_pointer_cast<LeadActor>(actor)) {
                std::cout << "Lead Actor Detected: " << lead->GetName() << "\n";
            } else if (auto const support = std::dynamic_pointer_cast<SupportingActor>(actor)) {
                std::cout << "Supporting Actor Detected: " << support->GetName() << "\n";
            } else if (auto const guest = std::dynamic_pointer_cast<GuestActor>(actor)) {
                std::cout << "Guest Actor Detected: " << guest->GetName() << "\n";
            }
        }

    } catch (const ActorException &e) {
        std::cerr << "ActorException caught: " << e.what() << std::endl;
    } catch (const std::exception &e) {
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

/*
    /////////////////////////////////WATCHLIST
    std::cout << "\nWATCLIST\n";
    try {
        // making objects
        std::shared_ptr<MediaItem> movie1 = std::make_shared<Movie>("Inception");
        std::shared_ptr<MediaItem> movie2 = std::make_shared<Movie>("The Matrix");
        std::shared_ptr<MediaItem> movie3 = std::make_shared<Movie>("Interstellar");


        // Actors by inheritance
        std::shared_ptr<Actor> leadActorPtr = std::make_shared<LeadActor>("Robert Downey");
        std::shared_ptr<Actor> supportingActorPtr = std::make_shared<SupportingActor>("Chris Evans");
        std::shared_ptr<Actor> guestActorPtr = std::make_shared<GuestActor>("Scarlett Johansson");


        std::cout << "Lead Actor: " << leadActorPtr->GetName() << "\n";
        std::cout << "Supporting Actor: " << supportingActorPtr->GetName() << "\n";
        std::cout << "Guest Actor: " << guestActorPtr->GetName() << "\n";



        // Adding movies
        leadActor->AddFilm(movie1);
        supportingActor->AddFilm(movie2);
        guestActor->AddFilm(movie3);

        // testing function
        std::vector<std::shared_ptr<Actor>> actors = {leadActor, supportingActor, guestActor};
        for (const auto &actor: actors) {
            std::cout << *actor << ", Role: " << actor->GetRoleType() << ", Main Film: " << actor->GetMainRole()
                      << '\n';
        }

        // making lists for users
        std::unique_ptr<Watchlist> favorites = std::make_unique<FavoritesWatchlist>("User1");
        std::unique_ptr<Watchlist> recent = std::make_unique<RecentWatchlist>("User2");
        std::unique_ptr<Watchlist> recommendations = std::make_unique<RecommendationsWatchlist>("User3");

        // Adding to WatchList
        favorites->AddToWatchlist(movie1);
        favorites->AddToWatchlist(movie2);

        recent->AddToWatchlist(movie3);

        recommendations->AddToWatchlist(movie1);
        recommendations->AddToWatchlist(movie3);

        // Display
        std::cout << "\n--- Displaying Watchlists ---\n";
        favorites->DisplayWatchlist();
        recent->DisplayWatchlist();
        recommendations->DisplayWatchlist();

        // dyn_cast
        auto const *specificWatchlist = dynamic_cast<const FavoritesWatchlist *>(favorites.get());
        if (specificWatchlist) {
            std::cout << "Dynamic cast to FavoritesWatchlist successful.\n";
        } else {
            throw WatchlistException("Dynamic cast to FavoritesWatchlist failed.");
        }


        // Exceptions
        std::cout << "\n--- Testing Exceptions ---\n";
        recommendations->RemoveFromWatchlist(movie2);
    } catch (const WatchlistException &e) {
        std::cerr << "WatchlistException caught: " << e.what() << '\n';
    } catch (const std::exception &e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
    }
*/

    // Crearea watchlist-urilor
    std::unique_ptr<Watchlist<std::shared_ptr<MediaItem>>> favorites = std::make_unique<FavoritesWatchlist>("User1");
    std::unique_ptr<Watchlist<std::shared_ptr<MediaItem>>> recent = std::make_unique<RecentWatchlist>("User2");
    std::unique_ptr<Watchlist<std::shared_ptr<MediaItem>>> recommendations = std::make_unique<RecommendationsWatchlist>("User3");

    // Adăugarea de filme
    std::shared_ptr<MediaItem> movie1 = std::make_shared<Movie>("Inception");
    std::shared_ptr<MediaItem> movie2 = std::make_shared<Movie>("The Matrix");
    std::shared_ptr<MediaItem> movie3 = std::make_shared<Movie>("Interstellar");

    favorites->AddToWatchlist(movie1);
    favorites->AddToWatchlist(movie2);
    recent->AddToWatchlist(movie3);
    recommendations->AddToWatchlist(movie1);
    recommendations->AddToWatchlist(movie3);

    // Afișarea watchlist-urilor
    DisplayWatchlistInfo(*favorites);
    DisplayWatchlistInfo(*recent);
    DisplayWatchlistInfo(*recommendations);

    // Utilizarea Singleton
    [[maybe_unused]] Singleton* singleton = Singleton::GetInstance();
    Singleton::ShowMessage();

    // Utilizarea Observer
    Subject subject;
    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    subject.Attach(&observer1);
    subject.Attach(&observer2);


    subject.Notify("New movie added to watchlist");

    return 0;
}
