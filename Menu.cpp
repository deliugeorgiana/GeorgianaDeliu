#include "Menu.h"
#include "Movie.h"
#include "TVShow.h"
#include "Serial.h"
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

    int choice = -1;
    while (choice != 0) {
        cout << "\n--- Media Menu ---\n";
        cout << "1. List all items\n";
        cout << "2. Add a Movie\n";
        cout << "3. Add a TV Show\n";
        cout << "4. Add a Serial\n";
        cout << "5. Clone an Item\n";
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
            case 0:
                cout << "Exiting menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }
}
