#include "Seller.h"

Seller::Seller(string name, string username, string pass, string email, bool type, int Id)
	: Person(name, username, pass, email, type, Id) {

}
Seller::Seller(void) : Person() {

}