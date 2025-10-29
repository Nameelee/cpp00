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