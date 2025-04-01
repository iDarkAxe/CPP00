#include "Contact.hpp"

Contact::Contact()
{
	this->_FirstName = "";
	this->_LastName = "";
	this->_NickName = "";
	this->_PhoneNumber = "";
	this->_DarkestSecret = "";
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
