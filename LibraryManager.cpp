#include "LibraryManager.h"
#include "Borrowable.h"
#include "LibraryException.h"
#include <iostream>
#include <vector>
#include <string>

// Constructor: nothing special needed because the vector starts empty
LibraryManager::LibraryManager() {
}

// Destructor: deletes every dynamically allocated item in the vector
// This prevents memory leaks
LibraryManager::~LibraryManager() {
    for (LibraryItem* item : items) {
        delete item;
    }
    items.clear();
}

// addItem: adds a new LibraryItem pointer to the vector
// Throws an exception if the pointer is null
void LibraryManager::addItem(LibraryItem* item) {
    if (item == nullptr) {
        throw InvalidOperationException("Cannot add a null item.");
    }

    items.push_back(item);
}

// removeItem: searches for an item by ID and removes it from the vector
// Also deletes the object from memory
// Returns true if an item was removed, false if not found
bool LibraryManager::removeItem(const std::string& id) {
    for (std::vector<LibraryItem*>::iterator it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            items.erase(it);
            return true;
        }
    }

    return false;
}

// findItem: searches through the vector for an item with the matching ID
// Returns the pointer if found
// Throws ItemNotFoundException if no matching item exists
LibraryItem* LibraryManager::findItem(const std::string& id) const {
    for (LibraryItem* item : items) {
        if (item->getId() == id) {
            return item;
        }
    }

    throw ItemNotFoundException("Item with ID " + id + " was not found.");
}

// displayAll: prints all items in the library by calling displayInfo()
// Uses runtime polymorphism because displayInfo() is virtual
void LibraryManager::displayAll() const {
    if (items.empty()) {
        std::cout << "Library is empty." << std::endl;
        return;
    }

    std::cout << "Library Collection:" << std::endl;
    for (LibraryItem* item : items) {
        item->displayInfo();
        std::cout << "----------------------" << std::endl;
    }
}

// borrowItem: finds an item by ID and tries to borrow it
// Uses dynamic_cast to check whether the item implements Borrowable
// Throws exceptions if the item is not borrowable or already borrowed
void LibraryManager::borrowItem(const std::string& id) {
    LibraryItem* item = findItem(id);

    Borrowable* borrowableItem = dynamic_cast<Borrowable*>(item);
    if (borrowableItem == nullptr) {
        throw InvalidOperationException("This item cannot be borrowed.");
    }

    if (borrowableItem->isBorrowed()) {
        throw InvalidOperationException("This item is already borrowed.");
    }

    borrowableItem->borrowItem();
}

// returnItem: finds an item by ID and tries to return it
// Uses dynamic_cast to check whether the item implements Borrowable
// Throws exceptions if the item is not borrowable or not currently borrowed
void LibraryManager::returnItem(const std::string& id) {
    LibraryItem* item = findItem(id);

    Borrowable* borrowableItem = dynamic_cast<Borrowable*>(item);
    if (borrowableItem == nullptr) {
        throw InvalidOperationException("This item cannot be returned.");
    }

    if (!borrowableItem->isBorrowed()) {
        throw InvalidOperationException("This item is not currently borrowed.");
    }

    borrowableItem->returnItem();
}