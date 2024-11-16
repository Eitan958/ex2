#include "User.h"
#include <iostream>

void User::init(unsigned int id, std::string username, unsigned int age)
{
	_id = id;
	_username = username;
	_age = age;
	_amountOfDevices = 0;
	_deviceList.init();
}

void User::clear()
{
	_id = 0;
	_username = "";
	_age = 0;
	_deviceList.clear();
	_amountOfDevices = 0;

}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return _username;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices()
{
	return _deviceList;
}

void User::addDevice(Device newDevice)
{
	_deviceList.add(newDevice);
	_amountOfDevices++;
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* n = _deviceList.get_first();
	if (_amountOfDevices > 0)
	{
		while (n->get_next() != nullptr)
		{
			if (n->get_data().isActive())
			{
				return true;
			}
			else
			{
				return false;
			}
			n = n->get_next();
		}
	}
}
