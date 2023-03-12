#include <iostream>
#include<vector>
#include"Product.h"
#include"Store.h"
#include"CPU.h"
#include"SSD.h"
#include<vector>

static vector<CPU>cpuList;
static vector<SSD>ssdList;
static vector<Store>storeList;
static vector<Product>productList;

int main()
{
	Store apple;
	apple.capacity = 100;
	apple.location ="adana";
	apple.rent = 388;
	apple.setID(1);
	CPU c;
	SSD s;
	Product p;
	int productNum;
	int id{};

	
	
	cout << "choose your product to add :";
	cin >> productNum;
	switch (productNum)
	{
	case(1):
		c.addProduct(&cpuList);
		c.deleteItem(cpuList, 1);
		break;
	case(2):
		s.addProduct(&ssdList);
		break;
	default:
		break;
	}
	cout << "choose what u want to do";
	cin >> productNum;
	switch (productNum)
	{
	case(1):
		c.displayInfo(cpuList);
		s.displayInfo(ssdList);
		break;
	case(2):
		cout << "enter the id :";
		cin >> id;
		cout << "\n";
		c.updatePrice(cpuList, id);
		c.displayInfo(cpuList);
		break;
	default:
		break;
	}
	
	
	
  

    


  



    

   
}

