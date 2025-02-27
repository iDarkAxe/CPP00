/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:33 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/27 13:49:45 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
	;
}

Contact *PhoneBook::getContact(size_t selected)
{
	if (selected > 7)
	{
		std::cout << "Selected doesn't exist, number should be between 0-7" << std::endl;
		return (NULL);
	}
	return (&this->_Contact[selected]);
}

// void PhoneBook::addContact()
// {
// 	Contact contact;
// 	std::string str;
// 	std::cout << "Creating a contact :" << std::endl;
// 	std::cout << "Please enter a first name : ";
// 	getline(std::cin, str);
// 	contact.setFirstName(str);

// 	std::cout << "Please enter a last name : ";
// 	getline(std::cin, str);
// 	contact.setLastName(str);

// 	std::cout << "Please enter a nickname : ";
// 	getline(std::cin, str);
// 	contact.setNickName(str);

// 	std::cout << "Please enter a phone number : ";
// 	getline(std::cin, str);
// 	contact.setPhoneNumber(str);

// 	std::cout << "Please enter it's darkest secret : ";
// 	getline(std::cin, str);
// 	contact.setDarkestSecret(str);

// 	if (this->_index + 1 > 7)
// 		std::cout << "Replacing contact number " << this->_index % 8 << std::endl;
// 	this->_Contact[this->_index % 8] = contact;
// 	this->_index++;
// }

void PhoneBook::addContact()
{
	std::string str1, str2, str3, str4, str5;
	
	std::cout << "Creating a contact :" << std::endl;
	std::cout << "Please enter a first name : ";
	getline(std::cin, str1);
	
	std::cout << "Please enter a last name : ";
	getline(std::cin, str2);

	std::cout << "Please enter a nickname : ";
	getline(std::cin, str3);
	
	std::cout << "Please enter a phone number : ";
	getline(std::cin, str4);
	
	std::cout << "Please enter it's darkest secret : ";
	getline(std::cin, str5);
	
	Contact contact(str1, str2, str3, str4, str5);
	if (this->_index + 1 > 7)
		std::cout << "Replacing contact number " << this->_index % 8 << std::endl;
	this->_Contact[this->_index % 8] = contact;
	this->_index++;
}

void PhoneBook::printTable()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "|" << "         " << i << "|";
		std::cout.width(10);
		std::cout << std::right << this->getContact(i)->getFirstName() << "|";
		std::cout.width(10);
		std::cout << std::right << this->getContact(i)->getLastName() << "|";
		std::cout.width(10);
		std::cout << std::right << this->getContact(i)->getNickName() << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::searchContact()
{
	std::string str;
	int index;
	this->printTable();
	do
	{
		if (static_cast<int>(this->_index) == 0)
		{
			std::cout << "No contact yet to select" << std::endl;
			return ;
		}
		do 
		{
			std::cout << "Please enter a contact number [0-7] : ";
			getline(std::cin, str);
		}
		while(str == "" || !str.find_first_not_of("0123456789"));
		index = std::atoi(str.c_str());
		if (index < 0 || index > 7)
		{
			std::cout << "Contact number should be between 0-7" << std::endl;
		}
		else if (static_cast<int>(this->_index) < index + 1)
		{
			std::cout << "Contact number " << index << " doesn't exist yet" << std::endl;
		}
	} while (index < 0 || index > 7 || static_cast<int>(this->_index) < index + 1);
	
	this->getContact(index)->printContact();
}
