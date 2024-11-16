#include "SocialNetwork.h"
#include <string>

void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_profileList.init();
	_minAge = minAge;
}

void SocialNetwork::clear()
{
	_networkName = "";
	_profileList.clear();
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profileToAdd)
{
	if(profileToAdd.getOwner().getAge() < _minAge)
	{
		return false; 
	}
	else
	{
		_profileList.add(profileToAdd);
	}
}

std::string SocialNetwork::getWindowsDevices() const
{
	ProfileNode* curr = _profileList.get_first();
	DeviceNode* deviceCurr = curr->get_data().getOwner().getDevices().get_first();
	std::string windowsDevicesString = "";
	while (curr != nullptr)
	{
		while (deviceCurr != nullptr)
		{
			if (deviceCurr->get_data().getOS() == WINDOWS7 ||
				deviceCurr->get_data().getOS() == WINDOWS10 ||
				deviceCurr->get_data().getOS() == WINDOWS11)
			{
				windowsDevicesString = windowsDevicesString + "[" + std::to_string(deviceCurr->get_data().getID()) + ", " + deviceCurr->get_data().getOS() + "], ";
			}
			deviceCurr = deviceCurr->get_next();
		}
		curr = curr->get_next();
		if(curr != nullptr)
		{ 
			deviceCurr = curr->get_data().getOwner().getDevices().get_first();
		}
		
	}
	//windowsDevicesString = windowsDevicesString + "[" + std::to_string(curr->get_data().getOwner().getDevices().get_first()->get_data().getID()) + ", " + curr->get_data().getOwner().getDevices().get_first()->get_data().getOS() + "]";
	if (windowsDevicesString.length())
	{
		windowsDevicesString.pop_back();
		windowsDevicesString.pop_back();
	}
	return windowsDevicesString;
}
