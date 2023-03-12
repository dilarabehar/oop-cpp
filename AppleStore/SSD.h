#pragma once
#include "product.h"
#include<iostream>
class SSD :public Product
{
public:
	int size;
	int readRate{};
	int writeRate{};
	string connectionType;

	virtual void addProduct(vector<SSD>*v);
	static void displayInfo(vector<SSD>v);
	virtual void updatePrice(vector<SSD>v, int id);
	void deleteItem(vector<SSD>& v, int id);



	/*
	
	friend std::ostream& operator<< (std::ostream& out, const SSD& d)
	{
		out << "In Derived\n";
		// static_cast Derived to a Base object, so we call the right version of operator<<
		out << static_cast<const Product&>(d);
		return out;
	}
	
	
	*/


};

