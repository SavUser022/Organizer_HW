#pragma once
#include "Product.h"
class Assistant
{
private:
	std::vector <Product> prod;
public:
	void loadData();
	void saveData();
	void displayProducts() const;
	void addNewProduct();
	void delExistProduct();
	void displayMeat() const;
};

