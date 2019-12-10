#include "InventoryObject.hpp"
#include <string>

InventoryObject::InventoryObject()
{
	name = "";
}

InventoryObject::~InventoryObject()
{
}

std::string InventoryObject::getName()
{
	return this->name;
}

void InventoryObject::setName(std::string incName)
{
	this->name = incName;
}
