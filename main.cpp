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

    // afiseaza ce contine media
    std::cout << *film1 << std::endl;
    std::cout << *film2 << std::endl;
    std::cout << *film3 << std::endl;

    // adauga genuri de filme
    film1->AddGenre("Sci-Fi");
    film1->AddGenre("Thriller");
    film2->AddGenre("Romance");
    film2->AddGenre("Drama");
    film3->AddGenre("Sci-Fi");
    film3->AddGenre("Action");

    // face use+adauga la favorite
    User utilizator("Alice", "English");
    utilizator.AddToFavorites(film1);
    utilizator.AddToFavorites(film2);

    // spune informatia despre user
    std::cout << utilizator << std::endl;
    std::cout << "Top favorite: " << (utilizator.GetTopFavorite() ? utilizator.GetTopFavorite()->GetInfo() : "N/A") << std::endl;

    // face un actor si adauga filme
    Actori actor("Leonardo DiCaprio");
    actor.AddFilm(film1);
    actor.AddFilm(film2);
    actor.AddFilm(film3);

    // da informatia despre actor
    std::cout << actor << std::endl;
    std::cout << "Main role: " << actor.GetMainRole() << std::endl;

    // creaza o categorie si adauga date media
    Categorie categorie("Sci-Fi", 120);
    categorie.AddMediaItem(film1);
    categorie.AddMediaItem(film3);

    // afiseaza inf despre categorie
    std::cout << categorie << std::endl;
    std::cout << "Is popular category? " << (categorie.IsPopular() ? "Yes" : "No") << std::endl;
    const auto topItem = categorie.GetTopItem();
    if (topItem) {
        std::cout << "Top item in category: " << topItem->GetInfo() << std::endl;
    }

    // face un watchlist
    Watchlist watchlist("Alice");
    watchlist.AddToWatchlist(film1);
    watchlist.AddToWatchlist(film2);
    watchlist.AddToWatchlist(film3);

    // afiseaza watchlist ul
    std::cout << "Initial Watchlist:" << std::endl;
    watchlist.DisplayWatchlist();

    // scpate un film si afiseaza lista de dupa
    watchlist.RemoveFromWatchlist(film2);
    std::cout << "Watchlist after removing Titanic:" << std::endl;
    watchlist.DisplayWatchlist();

    return 0;
}
