#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->_FirstName = firstName;
	this->_LastName = lastName;
	this->_NickName = nickName;
	this->_PhoneNumber = phoneNumber;
	this->_DarkestSecret = darkestSecret;
}

Contact::~Contact()
{
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

void Contact::printContact()
{
	std::cout << "First name : ";
	std::cout << this->_FirstName << std::endl;
	std::cout << "Last name : ";
	std::cout << this->_LastName << std::endl;
	std::cout << "Nickname : ";
	std::cout << this->_NickName << std::endl;
	std::cout << "Phone number : ";
	std::cout << this->_PhoneNumber << std::endl;
	std::cout << "Darkest secret : ";
	std::cout << this->_DarkestSecret << std::endl;
}

// void Contact::setFirstName(std::string str)
// {
// 	this->_FirstName = str;
// }

// void Contact::setLastName(std::string str)
// {
// 	this->_LastName = str;
// }

// void Contact::setNickName(std::string str)
// {
// 	this->_NickName = str;
// }

// void Contact::setPhoneNumber(std::string str)
// {
// 	this->_PhoneNumber = str;
// }

// void Contact::setDarkestSecret(std::string str)
// {
// 	this->_DarkestSecret = str;
// }
