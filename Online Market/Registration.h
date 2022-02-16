#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Person.h"
#include "Seller.h"
#include "Buyer.h"
#include "Product.h"
using namespace std;
class Registration
{
public:
	//Registration r;

	Product p;
	vector<Buyer> B;
	vector<Product> P;
	vector <Seller> S;
	//Registration();
	void test();
	int Signin(vector <Seller> s);
	vector <Seller> Signup(vector <Seller> s, int type);
	int Signin(vector <Buyer> b);
	vector <Buyer> Signup(vector <Buyer> b, int type);
};

