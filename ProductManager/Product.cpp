#include "Header.h"
#include "Product.h"

Product::Product() : id(0), weight(0.0), count(0), name("NONE"), type("NO TYPE")
{
}

Product::Product(int id, std::string name, std::string type, double weight, int count)
	: id(id), count(count), name(name), type(type) , weight(weight)
{
}

Product::Product(const Product& item)
{
	this->id = item.id;
	this->count = item.count;
	this->name = item.name;
	this->type = item.type;
}

int Product::getId() const
{
	return id;
}

double Product::getWeight() const
{
	return weight;
}

int Product::getCount() const
{
	return count;
}

std::string Product::getType() const
{
	return type;
}

std::string Product::getName() const
{
	return name;
}

void Product::display() const
{
	std::cout << "ID:" << id << std::endl;
	std::cout << "Weight:" << weight << std::endl;
	std::cout << "Count:" << count << std::endl;
	std::cout << "Name:" << name << std::endl;
	std::cout << "Type:" << type << std::endl;
}
