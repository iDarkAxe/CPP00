/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:33 by ppontet           #+#    #+#             */
/*   Updated: 2025/03/27 15:38:34 by ppontet          ###   ########lyon.fr   */
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

void PhoneBook::addContact()
{
	std::string str[5];
	
	std::cout << "Creating a contact :" << std::endl;
	std::cout << "Please enter a first name : ";
	getline(std::cin, str[0]);
	
	std::cout << "Please enter a last name : ";
	getline(std::cin, str[1]);

	std::cout << "Please enter a nickname : ";
	getline(std::cin, str[2]);
	
	std::cout << "Please enter a phone number : ";
	getline(std::cin, str[3]);
	
	std::cout << "Please enter it's darkest secret : ";
	getline(std::cin, str[4]);
	
	Contact contact(str[0], str[1], str[2], str[3], str[4]);
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
