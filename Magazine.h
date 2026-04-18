#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <string>
#include "LibraryItem.h"
#include "Borrowable.h"
using namespace std;

class Magazine : public LibraryItem, public Borrowable
{
private:
	string issue;
	bool borrowed;
public:
	Magazine(const string& id, const string& title, const string& author, int year, const string& issue);

	void displayInfo() const override;
	string getType() const override;

	void borrowItem() override;
	void returnItem() override;
	bool isBorrowed() const override;
};

#endif