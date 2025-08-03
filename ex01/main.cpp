/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:23 by ppontet           #+#    #+#             */
 /*   Updated: 2025/04/01 12:23:24 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
To make std::cin reusable after a close from Ctrl+D, you can :
#include <fstream>

getline(std::cin, str);
if (!std::cin.good())
{
	freopen("/dev/tty", "r", stdin);
	std::cin.ignore();
	std::cin.clear();
	continue;
}
It will works as no error ever existed (ignoring an error shouldn't be a great idea)
*/

int main(void)
{
	PhoneBook phonebook;
	std::string str;

	do 
	{
		std::cout << "Commands : ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Choice : ";
		getline(std::cin, str);
		if (!std::cin.good())
		{
			std::cout << "\033[0;31m" << "\nERROR : you closed stdin with Ctrl+D" << "\033[0m" << std::endl;
			return (1);
		}
		if (str.compare("ADD") == 0)
		{
			phonebook.addContact();
			// return (1);
		}
		else if (str.compare("SEARCH") == 0)
			phonebook.searchContact();
		else if (str.compare("EXIT") == 0)
			break;
		// else
			// std::cout << "\033[0;31m" << "ERROR : Command '" << str << "' not found" << "\033[0m" << std::endl;
	}
	while(1);
	return (0);
}
