#include "GroceryItem.h"

GroceryItem::GroceryItem()
{
	name = "";
	quantity = 0;
}

//Constructor
GroceryItem::GroceryItem(std::string& name, int quantity)
{
	this->name = name;
	this->quantity = quantity;
}

//Getters
std::string GroceryItem::getName()
{
	return name;
}

int GroceryItem::getQuantity()
{
	return quantity;
}

//Setters
void GroceryItem::setName(std::string newName)
{
	name = newName;
}

void GroceryItem::setQuantity(int newQuantity)
{
	quantity = newQuantity;
}

//Add quantity of item by one
int GroceryItem::addItem()
{
	quantity++;

	return quantity;
}
