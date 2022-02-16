#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
	string Name, UserName, Password, Email;
	bool buyer;
	int Id;
public:
	string getName();
	Person(void);
	Person(string name, string username, string pass, string email, bool type, int Id);
	bool srch(string username, string pass);
};

