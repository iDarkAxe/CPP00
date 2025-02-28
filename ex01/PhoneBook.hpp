#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACT 10

class PhoneBook{
	private:
		Contact _Contact[MAX_CONTACT];
		size_t _index;

	public:
		PhoneBook();
		~PhoneBook();

		Contact *getContact(size_t selected);
		void addContact();
		void searchContact();
		void printTable();
};

# endif
