/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:51:23 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/27 13:37:38 by ppontet          ###   ########lyon.fr   */
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
			std::cout << "Command not found" << std::endl;
	}
	while(1);
	return (0);
}