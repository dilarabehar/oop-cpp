#include"store.h"
#include<iostream>
#include"Product.h"
#include"SSD.h"
#include<vector>



/*
void updatePrice(vector<Product>v, int id)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].productID == id)
		{
			cout << "Enter the latest price of the product: ";
			cin >> v[i].price;
		}
	}

}
*/


void Product::deleteItem(vector<Product>v, int id)
{
	vector<Product>::iterator i;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].productID == id)
		{
			(v).erase(v.begin() + i);
		}
	}

}


void Product::addProduct(vector<Product>* v) {
	Product temp;

	int id;
	cout << "ID of the storage belongs to: ";
	cin >> id;
	temp.s.setID(id);

	cout << "Product Name: ";
	cin >> temp.name;

	cout << "Product ID: ";
	cin >> temp.productID;


	cout << "Amount of Product: ";
	cin >> temp.amount;

	cout << "Capacity: ";
	cin >> temp.capacity;

	cout << "Price: ";
	cin >> temp.price;

	(*v).push_back(temp);
}



void Product::displayInfo(vector<Product>v)
{
	if (v.empty())
	{
		cout << "product vektoru bos";
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << "productinfo\n";
		cout << "STORE\t\tNAME\t\tID\t\tAMOUNT\t\tCAPACITY\t\tPRICE\n";
		cout << v[i].s.getID() << "\t\t" << v[i].name << "\t\t" << v[i].productID << "\t\t" << v[i].amount << "\t\t" << v[i].capacity << "\t\t" << v[i].price;
	}
	
}




