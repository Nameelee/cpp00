#ifndef CONTACT_H // include guard
#define CONTACT_H

#include <string>

class Contact {

public:
	Contact(void);//generator
	~Contact(void);

	void setFirstName(std::string str);
	std::string getFirstName(void) const;

private:
	std::string _firstName;
};

#endif