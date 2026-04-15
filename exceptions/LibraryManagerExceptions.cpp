//
// Created by Erfan Tavassoli on 4/14/26.
//
#include "LibraryManagerExceptions.h"

ItemDoesNotExistException::ItemDoesNotExistException(const string& message)
    : runtime_error(message) {}

ItemCheckedOutException::ItemCheckedOutException(const string& message)
    : runtime_error(message) {}