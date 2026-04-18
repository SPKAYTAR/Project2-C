#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include <string>
#include "LibraryItem.h"
#include "Borrowable.h"
using namespace std;

class AudioBook : public LibraryItem, public Borrowable
{
private:
	string narrator;
	bool borrowed;
public:
	AudioBook(const string& id, const string& title, const string& author, int year, const string& narrator);

	void displayInfo() const override;
	string getType() const override;

	void borrowItem() override;
	void returnItem() override;
	bool isBorrowed() const override;
};

#endif
