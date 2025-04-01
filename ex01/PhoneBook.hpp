#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACT 8
#define MAX_FIELD 4
#define MAX_CHAR 10

class PhoneBook{
	private:
		Contact _Contact[MAX_CONTACT];
		size_t _index;
		

	public:
		PhoneBook();
		~PhoneBook();

		int addContact();
		int searchContact();
		void printTable();
};

# endif
