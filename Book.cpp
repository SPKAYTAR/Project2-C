#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(const string& id, const string& title, const string& author, int year, const string& genre) 
	: LibraryItem(id, title, author, year), genre(genre), borrowed(false)
{
}

void Book::displayInfo() const
{
	cout << "Type: " << getType() << endl;
	cout << "ID: " << getId() << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Year: " << getYear() << endl;
	cout << "Genre: " << genre << endl;
	cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
}

string Book::getType() const
{
	return "Book";
}

void Book::borrowItem()
{
	borrowed = true;
}
void Book::returnItem()
{
	borrowed = false;
}
bool Book::isBorrowed() const
{
	return borrowed;
}