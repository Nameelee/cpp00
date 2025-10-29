#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

void Contact::setFirstName(std::string str) {
	this->_firstName = str;
}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}