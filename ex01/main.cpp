#include <iostream>
#include <string>
#include "Phonebook.hpp"

int main(void) {

	PhoneBook phonebook;

	std::string command;

	std::cout << "Hallo. This is my humble phonebook" << std::endl;
	std::cout << "You can use: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "PhoneBook > ";
		std::getline(std::cin, command);

		if (std::cin.eof()) {
			std::cout << std::endl << "Your input was terminated. Shutting down the program." << std::endl;
			break;
		}

		if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.searchContacts();
		} else if (command == "EXIT") {
			break;
		} else {

		}

	}

	std::cout << "PhoneBook is finshed. All of your contacts will be dissapeard." << std::endl;
	return 0;
}