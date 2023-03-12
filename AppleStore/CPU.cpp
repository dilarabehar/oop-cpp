#include "CPU.h"


void CPU::displayInfo(vector<CPU>v)
{

	for (int i = 0; i < v.size(); i++)
	{
		cout << "cpuinfo\n";
		cout << "STORE\t\tNAME\t\tID\t\tAMOUNT\t\tCAPACITY\t\tPRICE\t\tCACHE SIZE\t\tCLOCK RATE\t\tNANOMETRE\n";
		cout << v[i].s.getID() << "\t\t" << v[i].name << "\t\t" << v[i].productID << "\t\t" << v[i].amount << "\t\t" << v[i].capacity << "\t\t" << v[i].price << "\t\t"<<v[i].cacheSize << "\t\t" << v[i].clockRate << "\t\t" << v[i].nanometre;
	}

}

void CPU::addProduct(vector<CPU>*v)
{
	Product:CPU temp;
	cout << "cpu'sproduct";
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

	cout << "Nanometre: ";
	cin >> temp.nanometre;

	cout << "Clock Rate: ";
	cin >> temp.clockRate;

	cout << "Cache Size: ";
	cin >> temp.cacheSize;

	(*v).push_back(temp);
}

 void CPU::updatePrice(vector<CPU>&v, int id)
{
	int price;
	vector<CPU>::iterator iter = v.begin();
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

 void CPU::deleteItem(vector<CPU>&v, int id)
 {
	 vector<CPU>::iterator iter =v.begin();
	 for (iter; iter < v.end(); iter++)
	 {
		 if (iter->productID == id)
		 {
			 v.erase(iter);
		 }
	 }
 }

