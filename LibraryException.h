#ifndef LIBRARYEXCEPTION_H
#define LIBRARYEXCEPTION_H

#include <exception>
#include <string>

// Base exception class for all library-related errors
class LibraryException : public std::exception {
protected:
    // Stores the error message
    std::string message;

public:
    // Constructor: saves the error message passed in
    LibraryException(const std::string& msg) : message(msg) {}

    // what(): returns the stored error message
    // This overrides std::exception::what()
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Exception used when an item ID cannot be found
class ItemNotFoundException : public LibraryException {
public:
    // Constructor: passes the message to the base class
    ItemNotFoundException(const std::string& msg) : LibraryException(msg) {}
};

// Exception used when a user tries an invalid action
class InvalidOperationException : public LibraryException {
public:
    // Constructor: passes the message to the base class
    InvalidOperationException(const std::string& msg) : LibraryException(msg) {}
};

#endif