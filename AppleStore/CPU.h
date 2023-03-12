#pragma once
#include "product.h"
#include<iostream>

class CPU : public Product
{
public:
	int nanometre{};
	int clockRate{};
	int cacheSize{};

	CPU(int nanometre=0) :nanometre(nanometre), clockRate(clockRate), cacheSize(cacheSize)//,Product(name,productID, amount, capacity, price)
	{

	}

	virtual void addProduct(vector<CPU>*v);
	static void displayInfo(vector<CPU>v);
	virtual void updatePrice(vector<CPU>&v, int id);
	virtual void deleteItem(vector<CPU>&v, int id);


};



