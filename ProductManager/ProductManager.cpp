#include "Header.h"
#include "Assistant.h"
#include "Menu.h"
#include "Product.h"


int main()
{
	bool stop = false;

	std::string name;
	std::vector<std::string> choices{
	"Display Products",
	"Add Product",
	"Delete Product",
	"Display Meat Products"
	};

	std::unique_ptr<Menu> menu(new Menu(name, choices));
	std::unique_ptr<Assistant> assistant(new Assistant);
	assistant->loadData();
	do
	{
		switch (menu->getChoice())
		{
		case 1:
			assistant->displayProducts();
			break;
		case 2:
			assistant->addNewProduct();
			break;
		case 3:
			assistant->delExistProduct();
			break;
		case 4:
			assistant->displayMeat();
			break;
		default:
			std::cout << "Your choice not exist" << std::endl;
			break;
		}
		if (stop) { break; }

	} while (menu->allowContinue() == false);
}