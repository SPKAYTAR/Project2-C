#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "LibraryItem.h"
#include "Borrowable.h"
using namespace std;

class Book : public LibraryItem, public Borrowable
{
private:
	string genre;

	//Tracks the borrow state
	bool borrowed;
public:
	Book(const string& id, const string& title, const string& author, int year, const string& genre);

	void displayInfo() const override;
	string getType() const override;

	void borrowItem() override;
	void returnItem() override;
	bool isBorrowed() const override;
};

#endif