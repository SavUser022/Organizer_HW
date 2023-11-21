#pragma once
class Menu
{
private:
	std::string name;
	std::vector<std::string> choices;
public:
	Menu(std::string name, std::vector<std::string> choices);
	Menu(const Menu& item);
	void display() const;
	int getChoice();
	bool allowContinue();
};

