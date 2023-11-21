#pragma once
class Product
{
	int id;
	double weight;
	int count;
	std::string name;
	std::string type;
public:
	Product();
	Product(int id, std::string name, std::string type, double weight, int count);
	Product(const Product& item);
	int getId() const;
	double getWeight() const;
	int getCount() const;
	std::string getType() const;
	std::string getName() const;
	void display() const;
	

};

