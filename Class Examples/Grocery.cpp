// Grocery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;


class GroceryItem
{
private:
	int stockNum;
	double price;
	int numInStock;
	double totalValue;
	void setStockNum();
	void setPrice();
	void setNumInStock();
	void calculateItemTotalValue();
public:
	void dataEntry();
	void displayItem();
};
void GroceryItem::dataEntry()
{
	setStockNum();
	setPrice();
	setNumInStock();
	calculateItemTotalValue();
}
void GroceryItem::setStockNum()
{
	int stockNum;
	cout << "Please enter the item's stock number (Must be between 1000-9999):  ";
	cin >> stockNum;
	if (stockNum < 1000 || stockNum > 9999)
	{
		cout << "Invalid Entry... Please enter a number between 1000 and 9999:  ";
		cin >> stockNum;
	}
	this->stockNum = stockNum;
}
void GroceryItem::setPrice()
{
	double price;
	cout << "Please enter the item's price:  ";
	cin >> price;
	if (price < 0)
	{
		cout << "Invalid Entry... Please enter a positive number:  ";
		cin >> price;
	}
	this->price = price;
}
void GroceryItem::setNumInStock()
{
	int numInStock;
	cout << "Please enter how many of this item are in stock:  ";
	cin >> numInStock;
	if (numInStock < 0)
	{
		cout << "Invalid Entry... Please enter a positive number:  ";
		cin >> numInStock;
	}
	this->numInStock = numInStock;
}
void GroceryItem::calculateItemTotalValue()
{
	this->totalValue = (this->price * this->numInStock);
}
void GroceryItem::displayItem()
{
	cout << endl << endl 
		<< "Current Item: " << endl
		<< "Stock #:             " << stockNum << endl
		<< "Price per item:      " << price << endl
		<< "Quantity Available:  " << numInStock << endl
		<< "Total value of stock:  $" << totalValue << endl;
}

int _tmain(int argc, _TCHAR* argv[]) 
{

	const int SIZE = 10;
	GroceryItem itemArray[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		itemArray[i].dataEntry();
	}

	for (size_t i = 0; i < SIZE; i++)
	{
		itemArray[i].displayItem();
	}

	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}


