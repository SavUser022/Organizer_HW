#include "Header.h"
#include "Menu.h"


Menu::Menu(std::string name, std::vector<std::string> choices) 
	: name(name), choices(choices)
{}

Menu::Menu(const Menu& item)
{
	this->name = item.name;
	for (int i = 0; i < choices.size(); i++)
	{
		this->choices[i] = item.choices[i];
	}
}

void Menu::display() const
{
	std::cout << "=================================" << std::endl;
	std::cout << name << std::endl;
	std::cout << "=================================" << std::endl;
	for (int i = 0; i < choices.size(); i++)
	{
		std::cout << choices[i] << std::endl;
	}
}

int Menu::getChoice()
{
	std::cout << "Make your choice" << std::endl;
	int number;
	std::cin >> number;
	return number;
}

bool Menu::allowContinue()
{
	std::cout << "Do you want to continue?" << std::endl;
	char yes ;
	std::cin >> yes;
	return (yes == 'y');
}
