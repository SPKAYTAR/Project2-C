#ifndef BORROWABLE_H
#define BORROWABLE_H

// Borrowable is an interface for items that can be borrowed and returned
class Borrowable {
public:
    // borrowItem: marks the item as borrowed, pure virtual function for you to implement
    virtual void borrowItem() = 0;

    // returnItem: marks the item as returned, pure virtual function, you implement.
    virtual void returnItem() = 0;

    // isBorrowed: returns true if the item is currently borrowed, pure virtual function, you implement.
    virtual bool isBorrowed() const = 0;

    // Virtual destructor for proper cleanup through interface pointers
    virtual ~Borrowable() {}
};

#endif