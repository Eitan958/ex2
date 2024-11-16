#pragma once
#include <string>
#include "ProfileList.h"


class SocialNetwork
{
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profileToAdd);
	std::string getWindowsDevices() const;




private:
	std::string _networkName;
	ProfileList _profileList;
	int _minAge;
};