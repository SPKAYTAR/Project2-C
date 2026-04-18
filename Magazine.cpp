#include "Magazine.h"
#include <iostream>
using namespace std;

Magazine::Magazine(const string& id, const string& title, const string& author, int year, const string& issue) 
	: LibraryItem(id, title, author, year), issue(issue), borrowed(false)
{
}

void Magazine::displayInfo() const
{
	cout << "Type: " << getType() << endl;
	cout << "ID: " << getId() << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Year: " << getYear() << endl;
	cout << "Issue: " << issue << endl;
	cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
}

string Magazine::getType() const
{
	return "Magazine";
}

void Magazine::borrowItem()
{
	borrowed = true;
}
void Magazine::returnItem()
{
	borrowed = false;
}
bool Magazine::isBorrowed() const
{
	return borrowed;
}
