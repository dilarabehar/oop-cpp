#include "SSD.h"
#include<iostream>

void SSD::displayInfo(vector<SSD>v)
{

	for (int i = 0; i < v.size(); i++)
	{
		cout << "ssdinfo\n";
		cout << "STORE\t\tNAME\t\tID\t\tAMOUNT\t\tCAPACITY\t\tPRICE\t\tCACHE SIZE\t\tCONNECTION TYPE\t\tREAD RATE\t\tWRITE RATE\n";
		cout << v[i].s.getID() << "\t\t" << v[i].name << "\t\t" << v[i].productID << "\t\t" << v[i].amount << "\t\t" << v[i].capacity << "\t\t" << v[i].price << "\t\t" << v[i].connectionType << "\t\t" << v[i].readRate << "\t\t" << v[i].writeRate;
	}

}



void SSD::addProduct(vector<SSD>*v)
{
	Product:SSD temp;

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

	cout << "SSD Size: ";
	cin >> temp.size;

	cout << "Read Rate: ";
	cin >> temp.readRate;

	cout << "Write Rate: ";
	cin >> temp.writeRate;

	cout << "Connection Type: ";
	cin >> temp.connectionType;

	(*v).push_back(temp);

}

void SSD::updatePrice(vector<SSD>v, int id)
{
	int price;
	vector<SSD>::iterator iter = v.begin();
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

void SSD::deleteItem(vector<SSD>& v, int id)
{
	vector<SSD>::iterator iter = v.begin();
	for (iter; iter < v.end(); iter++)
	{
		if (iter->productID == id)
		{
			v.erase(iter);
		}
	}
}
