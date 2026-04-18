#include "AudioBook.h"
#include <iostream>
using namespace std;

AudioBook::AudioBook(const string& id, const string& title, const string& author, int year, const string& narrator) 
	: LibraryItem(id, title, author, year), narrator(narrator), borrowed(false)
{
}

void AudioBook::displayInfo() const
{
	cout << "Type: " << getType() << endl;
	cout << "ID: " << getId() << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Year: " << getYear() << endl;
	cout << "Narrator: " << narrator << endl;
	cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
}

string AudioBook::getType() const
{
	return "AudioBook";
}

void AudioBook::borrowItem()
{
	borrowed = true;
}
void AudioBook::returnItem()
{
	borrowed = false;
}
bool AudioBook::isBorrowed() const
{
	return borrowed;
}
