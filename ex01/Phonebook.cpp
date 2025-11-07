/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:17:36 by jelee             #+#    #+#             */
/*   Updated: 2025/11/07 17:17:42 by jelee            ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook(void) {
	this->_currentIndex = 0;
	this->_contactCount = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

/*
** ------------------------- (feature ADD) ---------------------------
*/
static std::string getInput(std::string prompt) {

	std::string input = "";

	while (true) {
		std::cout << prompt;
		std::getline(std::cin, input);//save the text from keyboard(cin) in 'input'

		if (std::cin.eof()) {
            std::cout << std::endl << "Your input was terminated. Shutting down the program." << std::endl;
            exit(0);
        }

		if (input.empty() == false) {
			break; 
		}
		std::cout << "Error\n You can't empty that field. Please input that field." << std::endl;
	}
	return input;
}

void PhoneBook::addContact(void) {

	std::cout << "----Add new contract----" << std::endl;
	std::string first = getInput("1. First Name: ");
	std::string last = getInput("2. Last Name: ");
	std::string nick = getInput("3. Nickname: ");
	std::string pnumbr = getInput("4. Phone Number: ");
	std::string secrt = getInput("5. Darkest Secret: ");

	this->_contacts[this->_currentIndex].setFirstName(first);
	this->_contacts[this->_currentIndex].setLastName(last);
	this->_contacts[this->_currentIndex].setNickname(nick);
	this->_contacts[this->_currentIndex].setPhoneNumber(pnumbr);
	this->_contacts[this->_currentIndex].setDarkestSecret(secrt);

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
		std::cout << std::right << std::setw(9) << str.substr(0, 9) << ".";
	} else {
		std::cout << std::right << std::setw(10) << str;
	}
}

/**
 * setw(9): set width as 9
 * str.substr(0, 9): show the string till the letter 
 */


static void printSearchHeader(void) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
}

void PhoneBook::displayContactDetails(int index) const {
	std::cout << std::endl;
	std::cout << "----info (Index: " << index << ")----"  << std::endl;
	std::cout << " 1.First Name: " << this->_contacts[index].getFirstName() << std::endl;;
	std::cout << " 2.Last Name: " << this->_contacts[index].getLastName() << std::endl;;
	std::cout << " 3.Nickname: " << this->_contacts[index].getNickname() << std::endl;;
	std::cout << " 4.Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;;
	std::cout << " 5.Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
 }

 /**
  * displayContactDetails function should approach _contact class ->
  * so it should not be the static function
  */

 void PhoneBook::searchContacts(void) {

	if (this->_contactCount == 0) {
		std::cout << "This phonebook is empty." <<std::endl;
		return ;
	}

	printSearchHeader();

	for (int i = 0; i < this->_contactCount; i++) {
		std::cout << "|" << std::right << std::setw(10) << i << "|"; //for index
		printFormattedCell(this->_contacts[i].getFirstName());
		std::cout << "|";
		printFormattedCell(this->_contacts[i].getLastName());
		std::cout << "|";
		printFormattedCell(this->_contacts[i].getNickname());
		std::cout << "|" <<std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

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
			std::cout << "Error\n Not valid index. Input number (from 0 ~ " << (this->_contactCount - 1) << ")" << std::endl;
		}
	}
 }
