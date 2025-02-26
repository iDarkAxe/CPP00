/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:38:31 by ppontet           #+#    #+#             */
/*   Updated: 2025/02/26 13:06:10 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact _Contact[8];
		size_t _index;

	public:
		PhoneBook();
		~PhoneBook();

		Contact *getContact(size_t selected);

		void addContact();
		void searchContact();
};
