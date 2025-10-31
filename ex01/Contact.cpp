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

void Contact::setLastName(std::string str) {
	this->_lastName = str;
}

void Contact::setNickname(std::string str) {
	this->_nickname = str;
}

void Contact::setDarkestSecret(std::string str) {
	this->_darkestSecret = str;
}

std::string Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string Contact::getLastName(void) const {
	return this->_lastName;
}

std::string Contact::getNickname(void) const {
	return this->_nickname;
}

std::string Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}
