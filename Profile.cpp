#include "Profile.h"
#include <iostream>

void Profile::init(User owner)
{
	_owner = owner;
	_page.init();
	_friendList.init();
}

void Profile::clear()
{

	_page.clearPage();
	_friendList.clear();
	//_owner.clear();
}

User Profile::getOwner() const
{
	return _owner;
}

void Profile::setStatus(std::string new_status)
{
	_page.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_friendList.add(friend_to_add);
}

std::string Profile::getPage() const
{
	std::string pageString = "Status: " + _page.getStatus() +"\n";
	pageString = pageString + "*******************\n" + "*******************\n";
	pageString = pageString + _page.getPosts();
	return pageString;
}

std::string Profile::getFriends()
{
	std::string friendString = "";
	UserNode* curr = _friendList.get_first();
	while (curr != nullptr)
	{
		friendString = friendString + curr->get_data().getUserName() + ",";
		curr = curr->get_next();
	}
	friendString.pop_back();
	return friendString;
}

std::string Profile::getFriendsWithSameNameLength()
{
	std::string friendString = "";
	UserNode* curr = _friendList.get_first();
	while (curr != nullptr)
	{
		if (curr->get_data().getUserName().length() == _owner.getUserName().length())
		{
			friendString = friendString + curr->get_data().getUserName() + ",";
		}
		curr = curr->get_next();
	}

	if (friendString.length())
	{
		friendString.pop_back();
	}
	return friendString;
}

void Profile::changeAllWordsInStatus(std::string word)
{
	std::string newStatus = "";
	int wordCounter = 0;
	int i = 0;
	for (i = 0; i <= _page.getStatus().length(); i++)
	{
		if (_page.getStatus()[i] == ' ')
		{
			newStatus = newStatus + word + " ";
		}
		else if(_page.getStatus()[i] == '\n')
		{
			newStatus = newStatus + word + "\n";
		}

	}
	newStatus = newStatus + word;
	_page.setStatus(newStatus);
}


void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word)
{
	std::string newStatus = "";
	newStatus = _page.getStatus();
	int i = 0;
	int where = newStatus.find(word_to_replace);
	for (i = 0; i <= newStatus.length(); i++)
	{
		if (i == where)
		{
			newStatus.replace(where, word_to_replace.length(), new_word);
			where = newStatus.find(word_to_replace, where + new_word.length());
		}
	}
	_page.setStatus(newStatus);
}
