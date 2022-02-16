#include "Registration.h"

void Registration::test() {
	if (p.emptyCart) {
		for (int i = 0; i < p.add.size(); i++) {
			p.add.erase(p.add.begin() + i);
		}
		p.emptyCart = false;
	}
	int choice, id;
start:cout << "          Welcome to our Online Market Application\n"
<< "              We hope you find what you want\n" <<
"         ******************************************\n" <<
"1- New User? Sign Up \n2- Already have account? Log In\n" <<
"Select your choice: ";
cin >> choice;
switch (choice) {
	// SignUp
case 1:
SortSignUp:
	cout << "         ******************************************\n";
	cout << "1- Seller\n2- buyer\n" << "Select your choice: ";
	cin >> choice;
	switch (choice)
	{
		// seller
	case 1:
		S = Signup(S, choice);
		id = S.size() - 1;
	SellerSignUp:
		cout << "          *******************\n           Welcome, " << S[id].getName() <<
			"\n          *******************\n";
		cout << "\n1- Add new product \n2- Display your products\n3- Sign Out\n" <<
			"Select your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			P = p.addProduct(P, id);
			goto SellerSignUp;
			break;
		case 2:
			p.displayProduct(P, id);
			goto SellerSignUp;
			break;
		case 3:
			goto start;
			break;
		default:
			cout << "\nInvalid choice\n";
			goto SellerSignUp;
			break;
		}
		break;
		// buyer
	case 2:
		try
		{
			B = Signup(B, choice);
			id = B.size() - 1;
			if (P.at(id).DisplayCategories(P, B, id)) {
				goto start;
			}
		}
		catch (const std::exception&)
		{
		WrongCategory:
			cout << "\nNo Categories to be shown\n\n";
			cout <<
				"1- Sign Out\n" <<
				"2- Exit\n";
			cin >> choice;
			switch (choice) {
			case 1:
				goto start;
				break;
			case 2:
				exit(0);
			default:
				cout << "\nInvalid choice\n";
				goto WrongCategory;
				break;
			}
		}
		break;
	default:
		cout << "\nInvalid choice\n";
		goto SortSignUp;
		break;
	}
	break;
	// LogIn
case 2:
SortLogIn:
	cout << "         ******************************************\n";
	cout << "1- Seller\n2- buyer\n" << "Select your choice: ";
	cin >> choice;
	switch (choice) {
		//Seller
	case 1:
		id = Signin(S);
	SellerLogIn:
		cout << "          *******************\n           Welcome, " << S[id].getName() <<
			"\n          *******************\n";
		cout << "\n1- Add new Product \n2- Display your Products\n3- Sign Out\n" <<
			"Select your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			P = p.addProduct(P, id);
			goto SellerLogIn;
			break;
		case 2:
			p.displayProduct(P, id);
			goto SellerLogIn;
			break;
		case 3:
			goto start;
			break;
		default:
			cout << "\nInvalid choice\n";
			goto SellerLogIn;
			break;
		}
		break;
		//Buyer
	case 2:
		try {
			id = Signin(B);
			if (P.at(id).DisplayCategories(P, B, id)) {
				goto start;
			}
		}
		catch (const std::exception&)
		{
		NoCategories:

			cout << "\nNo Categories to be shown\n\n";
			cout <<
				"1- Sign Out\n" <<
				"2- Exit\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
				test();
				break;
			case 2:
				exit(0);
				break;
			default:
				cout << "\nInvalid choice\n";
				goto NoCategories;
				break;
			}
		}
		break;
	default:
		cout << "\nInvalid choice\n";
		goto SortLogIn;
		break;
	}
	break;
default:
	cout << "\nInvalid choice\n";
	goto start;
	break;
}
}


int Registration::Signin(vector <Seller> s) {
	string name, pass;
	int choice;
SignIn:
	cout << "         ******************************************\n";
	cout << "Please enter your Username: ";
	cin >> name;
	cout << "Please enter your Password: ";
	cin >> pass;
	for (int i = 0; i < s.size(); i++) {
		if (s[i].srch(name, pass)) {
			return i;
		}
	}
	cout << "\nInvalid Username or Password\n\n";
Invalid:
	cout << "1- Reenter your data\n" <<
		"2- Back to Start Page\n" <<
		"3- Exit\n" <<
		"Select your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		goto SignIn;
		break;
	case 2:
		test();
		break;
	case 3:
		exit(0);
	default:
		cout << "\nInvalid choice\n";
		goto Invalid;
		break;
	}

}
vector <Seller> Registration::Signup(vector <Seller> s, int type) {
	string Name, usname, pass, Email;

	cout << "        ***************************************" <<
		"\n         Please fill the following information\n" <<
		"        ***************************************\n";
	cout << "Enter your username: ";
	cin >> usname;
	cout << "Enter your Password: ";
	cin >> pass;
	cout << "Enter your Name: ";
	cin.ignore();
	getline(cin, Name);
	cout << "Enter your Email: ";
	cin >> Email;
	Seller temp(Name, usname, pass, Email, type, s.size() - 1);
	s.push_back(temp);
	return s;
}

vector <Buyer> Registration::Signup(vector <Buyer> b, int type) {
	string Name, usname, pass, address, Email;
	int phone_number;
	cout << "        ***************************************" <<
		"\n         Please fill the following information\n" <<
		"        ***************************************\n";
	cout << "Enter your Username: ";
	cin >> usname;
	cout << "Enter your Password: ";
	cin >> pass;
	cout << "Enter your Name: ";
	cin.ignore();
	getline(cin, Name);
	cout << "Enter your Address: ";
	cin >> address;
	cout << "Enter your Email: ";
	cin >> Email;
	cout << "Enter your phone number: ";
	cin >> phone_number;

	Buyer temp(Name, usname, pass, Email, type, b.size() - 1, address, phone_number);

	b.push_back(temp);

	return b;
}

int Registration::Signin(vector <Buyer> b) {
	string name, pass;
	int choice;
SignIn:
	cout << "         ******************************************\n";
	cout << "Please enter your Username: ";
	cin >> name;
	cout << "Please enter your Password: ";
	cin >> pass;
	for (int i = 0; i < b.size(); i++) {
		if (b[i].srch(name, pass)) {
			return i;
		}
	}
	cout << "\nInvalid Username or Password\n\n";
Invalid:
	cout << "1- Reenter your data\n" <<
		"2- Back to Start Page\n" <<
		"3- Exit\n" <<
		"Select your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		goto SignIn;
		break;
	case 2:
		test();
		break;
	case 3:
		exit(0);
	default:
		cout << "\nInvalid choice\n";
		goto Invalid;
		break;
	}

}
