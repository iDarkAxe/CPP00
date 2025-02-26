#include "Contact.hpp"

Contact::Contact()
{
	;
}

Contact::~Contact()
{
	;
}

std::string Contact::getFirstName()
{
	return (this->_FirstName);
}

std::string Contact::getLastName()
{
	return (this->_LastName);
}

std::string Contact::getNickName()
{
	return (this->_NickName);
}

std::string Contact::getPhoneNumber()
{
	return (this->_PhoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (this->_DarkestSecret);
}

void Contact::setFirstName(std::string str)
{
	this->_FirstName = str;
}

void Contact::setLastName(std::string str)
{
	this->_LastName = str;
}

void Contact::setNickName(std::string str)
{
	this->_NickName = str;
}

void Contact::setPhoneNumber(std::string str)
{
	this->_PhoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	this->_DarkestSecret = str;
}