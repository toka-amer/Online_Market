#include "Person.h"

Person::Person(string name, string username, string pass, string email, bool type, int Id) {
	this->Name = name;
	this->UserName = username;
	this->Password = pass;
	this->Email = email;
	this->buyer = type;
	this->Id = Id;
}
Person::Person(void) {
	this->Name = "";
	this->UserName = "";
	this->Password = "";
	this->Email = "";
	this->buyer = 0;
}
string Person::getName() {
	return Name;
}
bool Person::srch(string username, string pass) {
	if (this->UserName == username && this->Password == pass) {
		return true;
	}
	return false;
}