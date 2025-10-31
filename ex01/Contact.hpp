#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {

public:
	Contact(void);
	~Contact(void);

	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickname(std::string str);
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
};

#endif