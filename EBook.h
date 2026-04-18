#ifndef EBOOK_H
#define EBOOK_H

#include <string>
#include "LibraryItem.h"
#include "Borrowable.h"
using namespace std;

class EBook : public LibraryItem, public Borrowable
{
private:
	string format;
	bool borrowed;
public:
	EBook(const string& id, const string& title, const string& author, int year, const string& format);

	void displayInfo() const override;
	string getType() const override;

	void borrowItem() override;
	void returnItem() override;
	bool isBorrowed() const override;
};

#endif
