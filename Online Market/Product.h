#include <string>
#include <vector>
#include <iostream>
#include "Seller.h"
#include "Buyer.h"

using namespace std;

class Product
{
public:
    int ID, count, sellerID, num_of_category, price, total =0,cost = 0;
    string name, category;
     float rate=0;
     bool emptyCart = false;
    vector <string> all_categories;
    vector <Buyer> B;
    vector <Product> add;

    Product();
    Product(int ID, string name, string category, int price, int sellerID);
    ~Product();
    vector<Product> addProduct(vector<Product> p, int sellerID);
    void displayProduct(vector<Product> p, int sellerID);

    bool DisplayCategories(vector<Product>&p, vector<Buyer>&B, int id);

    bool Processing(vector <Product>&p, vector<Buyer> &B, int num_of_category);

    void DisplayItems(vector <Product>p, int no_categories);

    void Rate(vector<Product>&p);

    bool Receipt(vector<Product>&p);
};
