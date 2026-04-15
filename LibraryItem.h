#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>

// Abstract base class for all library items
class LibraryItem {

public:
    // Constructor: initializes the common fields
    LibraryItem(const std::string& id, const std::string& title,
                const std::string& author, int year);

    // Virtual destructor for proper polymorphic cleanup
    virtual ~LibraryItem();

    // getId: returns the unique item ID
    std::string getId() const;

    // getTitle: returns the title of the item
    std::string getTitle() const;

    // getAuthor: returns the author of the item
    std::string getAuthor() const;

    // getYear: returns the publication year
    int getYear() const;

    // displayInfo: pure virtual function to print item details
    virtual void displayInfo() const = 0;

    // getType: pure virtual function to return the item type
    virtual std::string getType() const = 0;

    protected:
    // Shared data for all library items
    std::string id;
    std::string title;
    std::string author;
    int year;
};

#endif