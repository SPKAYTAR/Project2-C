#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <vector>
#include <string>
#include "LibraryItem.h"

// LibraryManager controls the collection of library items
class LibraryManager {


public:
    // Constructor: creates an empty library manager
    LibraryManager();

    // Destructor: deletes all dynamically allocated items
    ~LibraryManager();

    // addItem: adds a new item pointer to the collection
    void addItem(LibraryItem* item);

    // removeItem: removes an item by ID
    // Returns true if removed, false if not found
    bool removeItem(const std::string& id);

    // findItem: searches for an item by ID
    // Returns a pointer to the found item
    // Throws ItemNotFoundException if not found
    LibraryItem* findItem(const std::string& id) const;

    // displayAll: prints information for every item in the library
    void displayAll() const;

    // borrowItem: borrows the item with the given ID
    // Throws exceptions if the item is not found or not borrowable
    void borrowItem(const std::string& id);

    // returnItem: returns the item with the given ID
    // Throws exceptions if the item is not found or cannot be returned
    void returnItem(const std::string& id);
    
    private:
    // Stores pointers to LibraryItem objects polymorphically
    std::vector<LibraryItem*> items;
};

#endif