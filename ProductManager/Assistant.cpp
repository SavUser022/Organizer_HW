#include "Header.h"
#include "Assistant.h"
#include "Product.h"

void Assistant::loadData()
{
	std::ifstream fin;
	fin.open("ProductStorage.txt");
	prod.clear();
	while (!fin.eof())
	{
		int id;
		double weight;
		int count;
		std::string	name;
		std::string	type;


		fin >> id;
		fin.ignore();
		fin >> weight;
		fin.ignore();
		fin >> count;
		std::getline(fin, name);
		std::getline(fin, type);
		Product pro(id, name, type, weight, count);
		prod.push_back(pro);
		std::cout << "Information about product has been added." << std::endl;
	}
	prod.pop_back();
	fin.close();
}

void Assistant::saveData()
{
	std::ofstream fout;
	fout.open("ProductStorage.txt");
	for (int i = 0; i < prod.size(); i++)
	{
		Product temp = prod[i];
		fout << temp.getId() << std::endl;
		fout << temp.getWeight() << std::endl;
		fout << temp.getCount() << std::endl;
		fout << temp.getName() << std::endl;
		fout << temp.getType() << std::endl;
	}
	fout.close();
	std::cout << "The data has been saved." << std::endl;
}

void Assistant::displayProducts() const
{
	if (prod.empty())
	{
		std::cout << "The list is empty." << std::endl;
	}
	else
	{
		const int N = prod.size();
		for (int i = 0; i < prod.size(); i++)
		{
			prod[i].display();
		}
	}
}

void Assistant::addNewProduct()
{
	//
	int id;
	double weight;
	int count;
	std::string name;
	std::string type;

	//
	id = prod.back().getId() + 1;
	std::cin.ignore();

	//
	//std::cout << "Input weight of product" << weight << std::endl;
	//std::getline(std::cin, weight);
	

	//
	//std::cout << "Input weight of product" << count << std::endl;
	//std::getline(std::cin, count);

	std::cin >> count;
	std::cin.ignore();

	std::cin >> weight;
	std::cin.ignore();
	//
	std::cout << "Input name of product" << name << std::endl;
	std::getline(std::cin, name);

	//
	std::cout << "Input type of product" << type << std::endl;
	std::getline(std::cin, type);

	//
	Product newProduct(id, name, type, weight, count );
	prod.push_back(newProduct);
	saveData();
}
void Assistant::delExistProduct()
{
	int id;
	std::cout << "Input id of product" << std::endl;
	std::cin >> id;

	auto iter = std::find_if(prod.begin(), prod.end(),
		[id](Product& item) {return (item.getId() == id);  });
	if (iter == prod.end())
	{
		std::cout << "Product with id" << id << " is None" << std::endl;
	}
	else
	{
		prod.erase(iter);
		saveData();
		std::cout << "The object with ID" << id << "Has been deleted" << std::endl;
	}
}

void Assistant::displayMeat() const
{
	std::for_each(prod.begin(), prod.end(), [](const Product& item)
		{if (item.getType() == "Риба")
		item.display();
		});
}

