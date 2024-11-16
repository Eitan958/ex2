#pragma once
#include "User.h"
#include "Page.h"
#include "UserList.h"


class Profile
{
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage() const;
	std::string getFriends();
	std::string getFriendsWithSameNameLength();
	void changeAllWordsInStatus(std::string word);
	void changeWordInStatus(std::string word_to_replace, std::string new_word);


private:
	User _owner;
	Page _page;
	UserList _friendList;
	
};