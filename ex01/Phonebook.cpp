#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip> // std::setw, std::right
#include <sstream> // std::stringstream
#include <cstdlib> // for exit()

PhoneBook::PhoneBook(void) {
	this->_currentIndex = 0;
	this->_contactCount = 0;
	return ;
}

PhoneBook::PhoneBook::~PhoneBook(void) {
	return ;
}

/*
** ------------------------- (feature ADD) ---------------------------
*/
static std::string getInput(std::string prompt) {

	std::string input = "";

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);//?

		if (std::cin.eof()) {
            std::cout << std::endl << "Your input was terminated. Shutting down the program." << std::endl;
            exit(0);
        }

		if (input.empty() == false) {//?
			break; 
		}
		std::cout << "Error\n You can't do like that. Please input again" << std::endl;
	}
	return input;
}

void PhoneBook::addContact(void) {

	std::cout << "----Add new contract----" << std::endl;
	std::string first = getInput("1. First Name: ");
	std::string last = getInput("2. Last Name: ");
	std::string nick = getInput("3. Nickname: ");

	this->_contacts[this->_currentIndex].setFirstName(first);
	this->_contacts[this->_currentIndex].setLastName(last);
	this->_contacts[this->_currentIndex].setNickname(nick);

	this->_currentIndex = (this->_currentIndex + 1) % 8;//to rewrite if over 7

	if (this->_contactCount < 8) {
		this->_contactCount++;
	}

	std::cout << "----Your Contract was saved successfully----" <<std::endl;
}

/*
** ------------------------- (feature SEARCH) ---------------------------
*/
static void printFormattedCell(std::string str) {

	if (str.length() > 10) {
		if (str.length() > 10) {
			//cut after 9 letter
			//align in right
			//put "." at 10th letter
			std::cout << std::right << std::setw(9) << str.substr(0, 9) << ".";//?
		} else {//if the input has less than 10 letter 
			std::cout << std::right << std::setw(10) << str;//align right
		} 
	}
}

static void printSearchHeader(void) {
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

void PhoneBook::displayContactDetails(int index) const {

	std::cout << "----info (Index: " << index << ") ----"  << std::endl;
	std::cout << " 1.First Name: " << this->_contacts[index].getFirstName()<< std::endl;
	std::cout << " 2.Last Name: " << this->_contacts[index].getLastName()<< std::endl;
	std::cout << " 3.Nickname: " << this->_contacts[index].getNickname()<< std::endl;
	std::cout << "---------------" << std::endl;
 }

 void PhoneBook::searchContacts(void) {

	if (this->_contactCount == 0) {
		std::cout << "This phonebook is empty." <<std::endl;
		return ;
	}

	printSearchHeader();

	for (int i = 0; i < this->_contactCount; i++) {
		std::cout << "|" << std::right << std::setw(10) << i << "|"; //for index
		printFormattedCell(this->_contacts[i].getFirstName());
	}
	std::cout << "-------------------------------------------" << std::endl;

	while (true) {
		std::cout << "Input the index number to see the details. (0 ~ " << (this-> _contactCount - 1) << "): ";
		std::string inputStr;
		std::getline(std::cin, inputStr);;

		if (std::cin.eof()) {
			std::cout << std::endl << "Terminated input." << std::endl;
			exit(0);
		}

		std::stringstream ss(inputStr);
		int index; 

		if (ss >> index && ss.eof() && index >=0 && index < this->_contactCount) {
			this->displayContactDetails(index);
			break;
		} else {
			std::cout << "Error: Not valid index. Input number (from 0 ~ " << (this->_contactCount - 1) << ")" << std::endl;
		}
	}

 }
