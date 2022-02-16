#include "Product.h"
#include<iostream>
using namespace std;

Product::Product(int ID, string name, string category, int price, int sellerID)
{
	this->name = name;
	this->category = category;
	this->price = price;
	this->sellerID = sellerID;
	this->ID = ID;

}

Product::Product() {
	name = "";
	category = "";
	price = 0;
	sellerID = 0;
	ID = 0;
	
}
vector<Product> Product::addProduct(vector<Product> p, int sellerID) {
	string name, category;
	int price;
	cout << "Enter product name: ";
	cin >> name;
	cout << "Enter product price: ";
	cin >> price;
	cout << "Enter category of product: ";
	cin >> category;
	Product prod(p.size()+1, name, category, price, sellerID);
	p.push_back(prod);
	return p;
}

void Product::displayProduct(vector <Product> p, int sellerID) {
	for (int i = 0; i < p.size(); i++) {
		if (p[i].sellerID == sellerID) {
			cout << p[i].name << " " << p[i].price << " " << p[i].category<< p[i].ID << endl;
		}
	}
}
bool Product::DisplayCategories(vector <Product>&p, vector <Buyer> &B, int id) {
	if (emptyCart) {
		for (int i = 0; i < add.size(); i++) {
			add.erase(add.begin() + i);
		}
		emptyCart = false;
	}
	int count = 0, count1 = 1, choice;
	cout << "          *******************\n           Welcome, " << B[id].getName() <<
		"\n          *******************\n" <<
		"------------- Categories -------------\n\n";
	for (int i = 0; i < p.size(); i++) {
		count = 0;
		for (int j = 0; j <= i; j++) {
			if (p[i].category == p[j].category)
			{
				count++;
			}
		}
		if (count == 1)
		{
			cout << count1 << ". " << p[i].category << endl;
			all_categories.push_back(p[i].category);
			count1++;
		}
	}
category:
	cout << "\n" <<
		"1- Select your Category\n" <<
		"2- Signout\n" <<
		"3- Exit\n" <<
		"Select your choice: ";
	cin >> choice;

displayCategory:
	switch (choice)
	{
	case 1:
		cout << "Please enter the category's number you want to see: ";
		cin >> num_of_category;
		//Validate the category number
		if (num_of_category < 0 && num_of_category > all_categories.size()) {
		InvalidCategory:
			cout <<
				"Invalid number !\n" <<
				"1- Reenter the Category's Number\n" <<
				"2- Sign Out\n" <<
				"3- Exit\n" <<
				"Select your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				goto displayCategory;
				break;
			case 2:
				emptyCart = true;
				return 1;
				break;
			case 3:
				exit;
			default:
				cout << "\nInvalid choice\n";
				goto InvalidCategory;
				break;
			}
		}
		if (Processing(p, B, num_of_category)) {
			return 1;
		}
		break;
	case 2:
		emptyCart = true;
		return 1;
	case 3:
		exit;
	default:
		cout << "Invalid choice !\n";
		goto category;
		break;
	}

}
bool Product::Processing(vector <Product>&p, vector <Buyer> &B, int num_of_category) {
	int choice, prod;
	DisplayItems(p, num_of_category);
addToCart:
	cout <<
		"1- Add to Cart\n" <<
		"2- Back to Categories\n" <<
		"3- SignOut\n" <<
		"4- Exit\n\n" <<
		"Select your choice: ";
	cin >> choice;
product:
	switch (choice)
	{
	case 1:
		cout << "Please enter the Product's ID you want to select: ";
		cin >> prod;
		if (add.empty()) {
			add.push_back(p[prod - 1]);
			cout << "\nThe selected Product has been added to your Cart Successfully.\n";
		}
		else {
			for (int i = 0; i < add.size(); i++) {
				if (p[prod - 1].ID == add[i].ID) {
				InvalidAdd:
					cout <<
						"Invalid number !\n" <<
						"1- Reenter the Product's Number\n" <<
						"2- Back to Categories\n" <<
						"3- Sign Out\n" <<
						"4- Exit\n" <<
						"Select your choice: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						goto product;
						break;
					case 2:
						goto display;
						break;
					case 3:
						emptyCart = true;
						return 1;
						break;
					case 4:
						exit(0);
					default:
						cout << "\Invalid choice\n";
						goto InvalidAdd;
						break;
					}
				}
				else if (i + 1 == add.size())
				{
					add.push_back(p[prod - 1]);
					cout << "\nThe selected Product has been added to your Cart Successfully.\n";
					break;
				}
			}
		}
	display:
		DisplayItems(p, num_of_category);
	cart:
		cout << endl <<
			"1- Add a Product\n" <<
			"2- Remove a Product\n" <<
			"3- Back to Categories\n" <<
			"4- Confirm your Order\n\n" <<
			"Select your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			goto product;
			break;
		remove:
		case 2:
			cout << "Please enter the Product's ID you want to remove: ";
			cin >> prod;

			for (int i = 0; i < add.size(); i++) {
				if (p[prod - 1].ID == add[i].ID) {
					add.erase(add.begin() + i);
					cout << "\nThe selected Product has been removed from your Cart successfully.\n";
					goto display;
				}
				else if (i + 1 == add.size()) {
				InvalidRemove:
					cout <<
						"Invalid number !\n" <<
						"1- Reenter the Product's Number\n" <<
						"2- Back to Categories\n" <<
						"3- Sign Out\n" <<
						"4- Exit\n" <<
						"Select your choice: ";
					cin >> choice;
					switch (choice)
					{
					case 1:
						goto remove;
						break;
					case 2:
						goto display;
						break;
					case 3:
						emptyCart = true;
						return 1;
						break;
					case 4:
						exit(0);
					default:
						cout << "\nInvalid choice\n";
						goto InvalidRemove;
						break;
					}
				}
			}
			break;
		case 3:
			DisplayCategories(p, B, B.size() - 1);
			break;
		case 4:
			if (Receipt(p)) {
				DisplayCategories(p, B, B.size() - 1);
			}
			else {
				return 1;
			}
			break;
		default:
			cout << "Invalid choice !\n";
			goto cart;
			break;
		}
		break;
	case 2:
		DisplayCategories(p, B, B.size() - 1);
		break;
	case 3:
		emptyCart = true;
		return 1;
		break;
	case 4:
		exit(0);
		break;
	default:
		cout << "Invalid choice !\n";
		goto addToCart;
		break;
	}
}

void Product::DisplayItems(vector <Product>p, int num_of_category)
{
	cout << "************************************************" << endl;
	//Name
	cout << "Name:      ";
	for (int i = 0; i < p.size(); i++) {
		if (p[i].category == all_categories[num_of_category - 1]) {
			cout << p[i].name << "    ";
		}
	}
	cout << "\n";
	//Price
	cout << "Price(L.E):";
	for (int i = 0; i < p.size(); i++) {
		if (p[i].category == all_categories[num_of_category - 1]) {
			cout << p[i].price << "         ";
		}
	}
	cout << "\n";
	//Seller ID
	cout << "Seller ID :";
	for (int i = 0; i < p.size(); i++) {
		if (p[i].category == all_categories[num_of_category - 1]) {
			cout << p[i].sellerID << "         ";
		}
	}
	cout << "\n";
	//Rate
	cout << "Rate:";
	for (int i = 0; i < p.size(); i++) {
		if (p[i].category == all_categories[num_of_category - 1]) {
			cout <<p[i].rate<< "         ";
		}
	}
	cout << "\n";
	//Product ID
	cout << "Product ID:";
	for (int i = 0; i < p.size(); i++) {
		if (p[i].category == all_categories[num_of_category - 1]) {
			cout << p[i].ID << "         ";
		}
	}
	cout << "\n";
	cout << "************************************************" << endl;
}

void Product::Rate(vector<Product>&p)
{
	 char isCheck;
	 float rate;
	for (int i = 0; i < add.size(); i++)
	{
		cout << "Would you like to rate this product (y/n) ?" << "(" << add[i].name << ")" << endl;
		cin >> isCheck;
		if (isCheck == 'Y' || isCheck == 'y')
		{
		rate:
			cout << "Enter your rate (1:5):"; 
			cin >> rate;
			if (rate > 0 && rate < 6) {
				p[add[i].ID - 1].rate = (rate + p[add[i].ID - 1].rate) / (total + 1);
				total++;
			}
			else {
				cout << "Invalid Rate\n";
				goto rate;
			}
		}
		else if (isCheck == 'N' || isCheck == 'n') {
			cout << "\nOops..!, I hope I know your opinion next time :)\n" << endl;
		}
	}
	cout << "Thank you" << endl;
}

bool Product::Receipt(vector<Product>&p)
{
	int choice;
	cout << "------------- The Receipt -------------\n\n";
	DisplayItems(add, num_of_category);
	cost = 0;
	for (int i = 0; i < add.size(); i++)
	{
		cost += add[i].price;
	}
	cout << "Your Total cost is: " << cost << endl;
	Rate(p);
	emptyCart = true;
	validat:
	cout <<
		"\n\n1- Back to Categories\n" <<
		"2- Sign Out\n" <<
		"3- Exit\n" <<
		"Select your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		return 1;
		break;
	case 2:
		emptyCart = true;
		return 0;
		break;
	case 3:
		exit(0);
	default:
		cout << "\nInvalid choice\n";
		goto validat;
		break;
	}
}



Product::~Product()
{
	//Des
}
