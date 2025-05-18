/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:33 by ppontet           #+#    #+#             */
/*   Updated: 2025/05/18 10:50:44 by ppontet          ###   ########lyon.fr   */
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

int PhoneBook::addContact()
{
	size_t		index;
	std::string str[5];
	std::string	element[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	std::cout << "Creating a contact :" << std::endl;
	index = 0;
	while (index < 5)
	{
		std::cout << "Please enter a " << element[index] << ": ";
		getline(std::cin, str[index]);
		if (!std::cin.good())
		{
			std::cout << "\033[0;31m" << "\nERROR : you closed stdin with Ctrl+D" << "\033[0m" << std::endl;
			return (1);
		}
		if (str[index].empty())
			std::cout << "\033[0;31m" << "ERROR : input shouldn't be empty" << "\033[0m" << std::endl;
		else
			index++;
	}
	
	Contact contact(str[0], str[1], str[2], str[3], str[4]);
	if (this->_index + 1 > MAX_CONTACT)
		std::cout << "Replacing contact number " << this->_index % MAX_CONTACT << std::endl;
	this->_Contact[this->_index % MAX_CONTACT] = contact;
	this->_index++;
	return (0);
}

void printContactTable(std::string str)
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

int PhoneBook::searchContact()
{
	std::string str;
	int index;
	
	this->printTable();
	if (static_cast<int>(this->_index) == 0)
	{
		std::cout << "No contact yet to select" << std::endl;
		return (0);
	}
	do 
	{
		std::cout << "Please enter a contact number [0-" << MAX_CONTACT - 1 << "] : ";
		getline(std::cin, str);
		if (!std::cin.good())
		{
			std::cout << "\033[0;31m" << "\nERROR : you closed stdin with Ctrl+D" << "\033[0m" << std::endl;
			return (1);
		}
		std::cin.clear();
		if (safe_atoi(str.c_str(), &index))
		{
			if (index < 0 || index > MAX_CONTACT - 1)
				std::cout << "\033[0;31m" << "ERROR : Contact number should be between 0-" << MAX_CONTACT - 1 << "\033[0m" << std::endl;
			else if (static_cast<int>(this->_index) < index + 1)
				std::cout << "\033[0;31m" << "ERROR : Contact number " << index << " doesn't exist yet" << "\033[0m" << std::endl;
			else
				break;
		}
	} while (1);
	this->_Contact[static_cast<size_t>(index)].printContact();
	return (0);
}
