#pragma once
#include <string>
#include <iostream>
#include "Person.h"
#include <string>


using namespace std;
class Buyer : public Person
{

public:
	string address;
	int phone_number;
	Buyer(void);
	Buyer(string name, string username, string pass, string email, bool type, int Id, string address, int phone_number);
};
