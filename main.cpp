#include <iostream>
#include <memory>
#include <string>
#include "Class_Media_Item.cpp"
#include "Class_User.cpp"
#include "Class_Actors.cpp"
#include "Class_Category.cpp"
#include "Class_WatchList.cpp"

int main() {
    auto film1 = std::make_shared<MediaItem>("Inception", 2010, 8.8f);
    auto film2 = std::make_shared<MediaItem>("Titanic", 1997, 7.9f);
    auto film3 = std::make_shared<MediaItem>("The Matrix", 1999, 8.7f);

    // Display MediaItem details
    std::cout << *film1 << std::endl;
    std::cout << *film2 << std::endl;
    std::cout << *film3 << std::endl;

    // Add genres to MediaItems
    film1->AddGenre("Sci-Fi");
    film1->AddGenre("Thriller");
    film2->AddGenre("Romance");
    film2->AddGenre("Drama");
    film3->AddGenre("Sci-Fi");
    film3->AddGenre("Action");

    // Create User and add favorites
    User utilizator("Alice", "English");
    utilizator.AddToFavorites(film1);
    utilizator.AddToFavorites(film2);

    // Display User information and favorites count
    std::cout << utilizator << std::endl;
    std::cout << "Top favorite: "
              << (utilizator.GetTopFavorite() ? utilizator.GetTopFavorite()->GetInfo() : "N/A")
              << std::endl;
    std::cout << "Favorite count for user: " << utilizator.FavoriteCount() << std::endl;

    // Create Actor and add films
    Actori actor("Leonardo DiCaprio");
    actor.AddFilm(film1);
    actor.AddFilm(film2);
    actor.AddFilm(film3);

    // Display Actor information and film count
    std::cout << actor << std::endl;
    std::cout << "Main role: " << actor.GetMainRole() << std::endl;
    std::cout << "Film count for actor: " << actor.FilmCount() << std::endl;

    // Create Category and add media items
    Categorie categorie("Sci-Fi", 120);
    categorie.AddMediaItem(film1);
    categorie.AddMediaItem(film3);

    // Display Category information
    std::cout << categorie << std::endl;
    std::cout << "Is popular category? " << (categorie.IsPopular() ? "Yes" : "No") << std::endl;
    const auto topItem = categorie.GetTopItem();
    if (topItem) {
        std::cout << "Top item in category: " << topItem->GetInfo() << std::endl;
    }

    // Create Watchlist and add media items
    Watchlist watchlist("Alice");
    watchlist.AddToWatchlist(film1);
    watchlist.AddToWatchlist(film2);
    watchlist.AddToWatchlist(film3);

    // Display initial Watchlist
    std::cout << "Initial Watchlist:" << std::endl;
    watchlist.DisplayWatchlist();

    // Remove a film and display updated Watchlist
    watchlist.RemoveFromWatchlist(film2);
    std::cout << "Watchlist after removing Titanic:" << std::endl;
    watchlist.DisplayWatchlist();

    return 0;
}
