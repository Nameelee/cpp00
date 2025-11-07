/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:18:14 by jelee             #+#    #+#             */
/*   Updated: 2025/11/07 17:18:20 by jelee            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContacts(void);

private:

	Contact _contacts[8];
	int _currentIndex;
	int _contactCount;

	void displayContactDetails(int index) const;
};

#endif
