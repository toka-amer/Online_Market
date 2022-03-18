#include "Buyer.h"


Buyer::Buyer(string name, string username, string pass, string email, bool type, int Id, string address, int phone_number)
	: Person(name, username, pass, email, type, Id) {
	this->address = address;
	this->phone_number = phone_number;
	// comment test
}

Buyer::Buyer(void) : Person() {
	this->address = "";
	this->phone_number = 0;
}

