#include "Menu.h"
#include "Movie.h"
#include "TVShow.h"
#include "Serial.h"
#include "Actor.h"
#include "LeadActor.h"
#include "SupportingActor.h"
#include "Category.h"
#include "DramaCategory.h"
#include "ComedyCategory.h"
#include "SciFiCategory.h"
#include "AdminUser.h"
#include "GuestUser.h"
#include "PremiumUser.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Initialize the singleton instance
Menu Menu::uniqueInstance;

// Return the unique instance
Menu& Menu::instance() {
    return uniqueInstance;
}


// Run the interactive menu
void Menu::run() {
    vector<shared_ptr<MediaItem>> items;

    // Initialize with some examples
    items.push_back(make_shared<Movie>("Inception", "A mind-bending thriller", 9.0f));
    items.push_back(make_shared<TVShow>("Breaking Bad", "A chemistry teacher turns to crime", 9.5f));

    // Add genres using the static function
    MediaItem::AddGenre("Action");
    MediaItem::AddGenre("Drama");
    MediaItem::AddGenre("Sci-Fi");

    // Create actors
    shared_ptr<Actor> actor1 = make_shared<LeadActor>("Leonardo DiCaprio");
    shared_ptr<Actor> actor2 = make_shared<SupportingActor>("Aaron Paul");

    // Add films to actors
    actor1->AddFilm(items[0]);  // Adding "Inception" movie to Leonardo DiCaprio's filmography
    actor2->AddFilm(items[1]);  // Adding "Breaking Bad" TV Show to Aaron Paul's filmography

    // Create categories
    shared_ptr<Category<int>> dramaCategory = make_shared<DramaCategory<int>>("Shakespearean Tragedy", 5);
    shared_ptr<Category<int>> comedyCategory = make_shared<ComedyCategory<int>>("Romantic Comedy", 3);
    shared_ptr<Category<int>> sciFiCategory = make_shared<SciFiCategory<int>>("Space Exploration", 10);

    // Create user instances
    shared_ptr<AdminUser<string>> adminUser = AdminUser<string>::GetInstance("Admin", "English");
    shared_ptr<GuestUser<string>> guestUser = make_shared<GuestUser<string>>("Guest", "Spanish");
    shared_ptr<PremiumUser<string>> premiumUser = make_shared<PremiumUser<string>>("PremiumUser", "English");


    int choice = -1;
    while (choice != 0) {
        cout << "\n--- Media Menu ---\n";
        cout << "1. List all items\n";
        cout << "2. Add a Movie\n";
        cout << "3. Add a TV Show\n";
        cout << "4. Add a Serial\n";
        cout << "5. Clone an Item\n";
        cout << "6. Add Genre\n";
        cout << "7. List Genres\n";
        cout << "8. Show Item Count\n";
        cout << "9. Display Films of Actor\n";
        cout << "10. Display Actor's Main Role and Role Type\n";
        cout << "11. Display Category Info\n";
        cout << "12. Display User Profiles\n";
        cout << "13. Report User (Admin only)\n";
        cout << "14. Recommend Content (Premium only)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (!items.empty()) {
                    cout << "Listing all items:\n";
                    for (const auto& item : items) {
                        cout << *item << "\n";
                    }
                } else {
                    cout << "No items available to list.\n";
                }
                break;
            }
            case 2: {
                string title, description;
                float rating;
                cout << "Enter movie title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter rating: ";
                cin >> rating;
                items.push_back(make_shared<Movie>(title, description, rating));
                break;
            }
            case 3: {
                string title, description;
                float rating;
                cout << "Enter TV show title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter rating: ";
                cin >> rating;
                items.push_back(make_shared<TVShow>(title, description, rating));
                break;
            }
            case 4: {
                string title, description;
                float rating;
                cout << "Enter serial title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter rating: ";
                cin >> rating;
                items.push_back(make_shared<Serial>(title, description, rating));
                break;
            }
            case 5: {
                if (!items.empty()) {
                    cout << "Select an item to clone (1-" << items.size() << "): ";
                    int index;
                    cin >> index;
                    if (index > 0 && static_cast<size_t>(index) <= items.size()) {
                        auto clonedItem = items[index - 1]->Clone();
                        cout << "Cloned Item: " << *clonedItem << endl;
                    } else {
                        cout << "Invalid selection.\n";
                    }
                } else {
                    cout << "No items to clone.\n";
                }
                break;
            }
            case 6: {
                string genre;
                cout << "Enter genre to add: ";
                cin.ignore();
                getline(cin, genre);
                MediaItem::AddGenre(genre);
                break;
            }
            case 7: {
                cout << "Genres list:\n";
                for (const auto& genre : MediaItem::GetGenres()) {
                    cout << genre << "\n";
                }
                break;
            }
            case 8: {
                cout << "Total number of items: " << MediaItem::GetItemCount() << endl;
                break;
            }
            case 9: {
                cout << "Enter actor name to display their films: ";
                string actorName;
                cin.ignore();
                getline(cin, actorName);

                if (actor1->GetName() == actorName) {
                    actor1->DisplayFilms();
                } else if (actor2->GetName() == actorName) {
                    actor2->DisplayFilms();
                } else {
                    cout << "Actor not found.\n";
                }
                break;
            }
            case 10: {
                cout << "Enter actor name to display their main role and role type: ";
                string actorName;
                cin.ignore();
                getline(cin, actorName);

                if (actor1->GetName() == actorName) {
                    cout << "Main Role: " << actor1->GetMainRole() << ", Role Type: " << actor1->GetRoleType() << endl;
                } else if (actor2->GetName() == actorName) {
                    cout << "Main Role: " << actor2->GetMainRole() << ", Role Type: " << actor2->GetRoleType() << endl;
                } else {
                    cout << "Actor not found.\n";
                }
                break;
            }
            case 11: {
                cout << "\nCategories:\n";
                cout << *dramaCategory << "\n";
                cout << *comedyCategory << "\n";
                cout << *sciFiCategory << "\n";
                break;
            }
            case 12: {
                cout << "\nDisplaying user profiles:\n";
                adminUser->DisplayProfile();
                guestUser->DisplayProfile();
                premiumUser->DisplayProfile();
                break;
            }
            case 13: {
                cout << "Enter the name of the user to report: ";
                string userName;
                cin.ignore();
                getline(cin, userName);

                if (userName == adminUser->GetName()) {
                    cout << "Admin users cannot be reported.\n";
                } else {
                    AdminUser<string>::ReportUser(*adminUser);
                }
                break;
            }
            case 14: {
                cout << "Enter the name of the premium user to recommend content for: ";
                string userName;
                cin.ignore();
                getline(cin, userName);

                if (userName == premiumUser->GetName()) {
                    premiumUser->RecommendContent();
                } else {
                    cout << "Only premium users can receive content recommendations.\n";
                }
                break;
            }
            case 0:
                cout << "Exiting menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
}

