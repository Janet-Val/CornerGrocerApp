#pragma once
#include <string>
#ifndef GROCERYITEM_H
#define GROCERYITEM_H

class GroceryItem
{
public:
	//Default constructor
	GroceryItem();

	//Constructor
	GroceryItem(std::string& name, int quantity);

	//Getters
	std::string getName();
	int getQuantity();

	//Setters
	void setName(std::string newName);
	void setQuantity(int newQuantity);

	//Adding method
	int addItem();

private:
	std::string name;
	int quantity;
};

#endif