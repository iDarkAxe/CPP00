/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:33 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/28 15:35:30 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include "ft_others.hpp"


PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
}

// Contact *PhoneBook::getContact(size_t selected)
// {
// 	if (selected > MAX_CONTACT)
// 	{
// 		std::cerr << "\033[0;31m" << "Selected doesn't exist, number should be between 0-"<< MAX_CONTACT - 1 << "\033[0m" << std::endl;
// 		return (NULL);
// 	}
// 	return (&this->_Contact[selected]);
// }

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
// 		std::cout << "Replacing contact number " << this->_index % MAX_CONTACT << std::endl;
// 	this->_Contact[this->_index % MAX_CONTACT] = contact;
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
	if (this->_index + 1 > MAX_CONTACT)
		std::cout << "Replacing contact number " << this->_index % MAX_CONTACT << std::endl;
	this->_Contact[this->_index % MAX_CONTACT] = contact;
	this->_index++;
}

void PhoneBook::printContactTable(std::string str)
{
	std::cout << "|";
	std::cout.width(MAX_CHAR);
	if (str.length() > MAX_CHAR)
		std::cout << std::right << str.substr(0, MAX_CHAR - 1).append(".");
	else
		std::cout << std::right << str;
}

void PhoneBook::printTable()
{
	std::string str;

	for(size_t i = 0; i < (MAX_FIELD * MAX_CHAR + MAX_FIELD + 1); i++)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (size_t i = 0; i < MAX_CONTACT; i++)
	{
		std::cout << "|";
		for (size_t j = 0; j < MAX_CHAR - count_digit(i); j++)
			std::cout << " ";
		std::cout << i;

		printContactTable(this->_Contact[i].getFirstName());
		printContactTable(this->_Contact[i].getLastName());
		printContactTable(this->_Contact[i].getNickName());
		
		std::cout << "|" << std::endl;
	}
	for(size_t i = 0; i < (MAX_FIELD * MAX_CHAR + MAX_FIELD + 1); i++)
		std::cout << "-";
	std::cout << std::endl;
}

void PhoneBook::searchContact()
{
	std::string str;
	int index;
	
	this->printTable();
	if (static_cast<int>(this->_index) == 0)
	{
		std::cout << "No contact yet to select" << std::endl;
		return ;
	}
	do 
	{
		std::cout << "Please enter a contact number [0-" << MAX_CONTACT - 1 << "] : ";
		getline(std::cin, str);
		std::cin.clear();
		if (safe_atoi(str.c_str(), &index))
		{
			if (index < 0 || index > MAX_CONTACT - 1)
				std::cerr << "\033[0;31m" << "ERROR : Contact number should be between 0-" << MAX_CONTACT - 1 << "\033[0m" << std::endl;
			else if (static_cast<int>(this->_index) < index + 1)
				std::cerr << "\033[0;31m" << "ERROR : Contact number " << index << " doesn't exist yet" << "\033[0m" << std::endl;
			else
				break;
		}
	} while (1);
	this->_Contact[static_cast<size_t>(index)].printContact();
}
