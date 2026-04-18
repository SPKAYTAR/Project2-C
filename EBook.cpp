#include "EBook.h"
#include <iostream>
using namespace std;

EBook::EBook(const string& id, const string& title, const string& author, int year, const string& format) 
	: LibraryItem(id, title, author, year), format(format), borrowed(false)
{
}

void EBook::displayInfo() const
{
	cout << "Type: " << getType() << endl;
	cout << "ID: " << getId() << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Year: " << getYear() << endl;
	cout << "Format: " << format << endl;
	cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
}

string EBook::getType() const
{
	return "EBook";
}

void EBook::borrowItem()
{
	borrowed = true;
}
void EBook::returnItem()
{
	borrowed = false;
}
bool EBook::isBorrowed() const
{
	return borrowed;
}
