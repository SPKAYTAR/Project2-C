//
// Created by Erfan Tavassoli on 4/14/26.
//

#ifndef DIGITAL_Library_LIBRARYMANAGEREXCEPTIONS_H
#define DIGITAL_Library_LIBRARYMANAGEREXCEPTIONS_H
#include <stdexcept>
#include <string>
using namespace std;

// Thrown when requested book doesn't exist
class ItemDoesNotExistException : public runtime_error {
public:
    explicit ItemDoesNotExistException(const string& message);
};

// Thrown when requested book is checked out already
class ItemCheckedOutException : public runtime_error {
public:
    explicit ItemCheckedOutException(const string& message);
};

#endif //DIGITAL_Library_LIBRARYMANAGEREXCEPTIONS_H
