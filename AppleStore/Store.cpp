#include"Store.h"
#include<vector>


void Store::setID(int id)
{
	ID = id;
}

int Store::getID()
{
	return ID;
}


 void Store::createStore(vector<Store>*v)
{
	Store temp;
	cout << "Enter the info about new store.\n";

	int id;
	cout << "Store ID: ";
	cin >> id;
	temp.setID(id);


	cout << "Location: ";
	cin >> temp.location;

	cout << "Rent: ";
	cin >> temp.rent;

	cout << "Capacity: ";
	cin >> temp.capacity;

	(*v).push_back(temp);
	

}


