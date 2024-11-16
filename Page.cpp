#include "Page.h"
#include <iostream>

void Page::init()
{
	_status = "";
	_posts = "";
}

std::string Page::getPosts() const
{
	return _posts;
}

std::string Page::getStatus() const
{
	return _status;
}

void Page::clearPage()
{
	_posts = "";
}

void Page::setStatus(std::string status)
{
	_status = status;
}

void Page::addLineToPosts(std::string newLine)
{
	std::string endLine = "\n";
	_posts = _posts + newLine + endLine;
}
