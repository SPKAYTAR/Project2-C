#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& id, const std::string& title, const std::string& author, int year)
{
	this->id = id;
	this->title = title;
	this->author = author;
	this->year = year;
}
LibraryItem::~LibraryItem()
{
}

std::string LibraryItem::getId() const
{
	return id;
}
std::string LibraryItem::getTitle() const
{
	return title;
}
std::string LibraryItem::getAuthor() const
{
	return author;
}
int LibraryItem::getYear() const
{
	return year;
}
