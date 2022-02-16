#pragma once
#include <string>
#include <iostream>
#include "Person.h"
using namespace std;
class Seller : public Person
{
public:
	Seller(void);
	Seller(string name, string username, string pass, string email, bool type, int Id);
	void displayProducts();
	void addProduct();
};

