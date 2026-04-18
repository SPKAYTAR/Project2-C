#include <iostream>
#include "LibraryManager.h"
#include "LibraryException.h"
#include "Borrowable.h"
#include "Book.h"
#include "AudioBook.h"
#include "Magazine.h"
#include "EBook.h"

int main() {
    LibraryManager manager;

    try {
        // Create multiple concrete media objects and store polymorphically.
        manager.addItem(new Book("B001", "1984", "George Orwell", 1949, "Dystopian"));
        manager.addItem(new AudioBook("A001", "Dune", "Frank Herbert", 1965, "Scott Brick"));
        manager.addItem(new Magazine("M001", "National Geographic", "Various", 2026, "April 2026"));
        manager.addItem(new EBook("E001", "Clean Code", "Robert C. Martin", 2008, "PDF"));

        std::cout << "=== Initial Collection ===" << std::endl;
        manager.displayAll(); // Runtime polymorphism via virtual displayInfo()

        std::cout << "\n=== Borrow Through Manager ===" << std::endl;
        manager.borrowItem("B001");
        manager.displayAll();

        std::cout << "\n=== Polymorphic Access (findItem + virtual call) ===" << std::endl;
        LibraryItem* item = manager.findItem("A001");
        item->displayInfo();

        std::cout << "\n=== Interface In Action (Borrowable*) ===" << std::endl;
        LibraryItem* magItem = manager.findItem("M001");
        Borrowable* borrowable = dynamic_cast<Borrowable*>(magItem);
        if (borrowable != nullptr) {
            borrowable->borrowItem();
            std::cout << "Magazine borrowed? " << (borrowable->isBorrowed() ? "Yes" : "No") << std::endl;
            borrowable->returnItem();
        }

        std::cout << "\n=== Exception Demo #1 ===" << std::endl;
        try {
            manager.borrowItem("X404"); // Not found
        } catch (const LibraryException& ex) {
            std::cout << "Caught exception: " << ex.what() << std::endl;
        }

        std::cout << "\n=== Exception Demo #2 ===" << std::endl;
        try {
            manager.returnItem("E001"); // E001 was never borrowed
        } catch (const LibraryException& ex) {
            std::cout << "Caught exception: " << ex.what() << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cout << "Unexpected error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
