#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

// This is the global space. It is for classes and global variables.
class invetory
{
	friend ostream& operator<<(ostream&, const invetory&);
	friend istream& operator>>(istream&, invetory&);
public:
	void zeroAll();
	void setPrice(int);
	void setStockNum(int);
private:
	int stockNum;
	int quantity;
	double price;
};
void invetory::setStockNum(int sn)
{
	stockNum = sn;
}
void invetory::setPrice(int p)
{
	price = p;
}
void invetory::zeroAll()
{
	stockNum = 0;
	quantity = 0;
	price = 0.0;
}

ostream& operator<<(ostream& out, const invetory& item)
{
	out << "item number " << item.stockNum << " has " << item.quantity << " on hand, and costs $" << item.price << endl;
	return out;
}

istream& operator>>(istream& in, invetory& item)
{
	const int high_stock = 999;
	const int low_stock = 0;
	const string stockmsg = "this is an invalid entry.";
	const int low_quantity = 0;
	const double high_price = 100.00;

	cout << "Enter stock number between 0 and 100.";
	in >> item.stockNum;
	if (item.stockNum < low_stock || item.stockNum > high_stock)
		throw(item);

	cout << "Enter the quantity of the item.";
	in >> item.quantity;
	if (item.quantity < low_quantity)
		throw(item); //invetory

	cout << "Enter the price of the item.";
	in >> item.price;
	if (item.price > high_price)
		throw(item); //invetory
	return in;
}
int main()
{
	// Place your main code here.
	const int numItems = 5;
	invetory items[numItems];
	int count = 0;

	//Data entry loop
	for (int i = 0; i < numItems; i++)
	{
		try
		{
			cout << "item number " << (i + 1) << endl;
			cin >> items[i];
			count = count + 1;
		}
		catch (...)
		{
			cout << "invalid entry" << endl;
			break;
		}
	}

	// output loop
	cout << endl;
	cout << "item list:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << items[i] << endl;
	}
	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}