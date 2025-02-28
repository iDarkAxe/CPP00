/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:23 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/28 12:22:05 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string str;

	do 
	{
		std::cout << "Commands : ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Choice : ";
		getline(std::cin, str);
		if (str.compare("ADD") == 0)
			phonebook.addContact();
		else if (str.compare("SEARCH") == 0)
			phonebook.searchContact();
		else if (str.compare("EXIT") == 0)
			break;
		else
			std::cout << "\033[0;31m" << "ERROR : Command '"<< str << "' not found" << "\033[0m"<< std::endl;
	}
	while(1);
	return (0);
}
