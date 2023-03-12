#pragma once
#include"store.h"
#include<iostream>
#include<vector>

class Product
{
public:
	string name;
	int productID{};
	int amount{};
	int capacity{};
	int price{};
	Store s;

	Product() :name(name), productID(productID), amount(amount), capacity(capacity), price(price)
	{

	}

	
	virtual void addProduct(vector<Product>*v);
	static void displayInfo(vector<Product>v);
	virtual void deleteItem(vector<Product>v, int id);
	//template <class T>
	 virtual void updatePrice(vector<Product>&v, int id)
	{
		 int price;
		 vector<Product>::iterator iter = v.begin();
		for (iter; iter < v.end(); iter++)//iterator dongusu yap.diger methodlari da degistir.
		{
		
			if (iter->productID == id)
			{
				cout << "Enter the latest price of the product: ";
				cin >> price;
				iter->price = price;
				cout << "new price: " << iter->price;
			}
		}

	}

	 friend std::ostream& operator<< (std::ostream& out, const Product& b)
	 {
		 out << "In Base\n";
		 out << b.productID << '\n';
		 return out;
	 }

};

