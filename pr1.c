#include "pr1.h"

int main()
{
	struct food_struct *Product[20];
	int number = 0;
	int menu;

	number = loadData(Product);

	while (1)
	{
		menu = selectProduct();
		getchar();
		if (menu == 0)
			break;
		if (menu == 1)
			number = plusProduct(Product, number);
		else if (menu == 2)
			readProduct(Product, number);
		else if (menu == 3)
			number = updateProduct(Product, number);
		else if (menu == 4)
			number = deleteProduct(Product, number);
		else if (menu == 5)
			saveProduct(Product, number);
		else if (menu == 6)
			searchProduct(Product, number);
	}
	printf("=> 종료\n");

	free(*Product);
	return 0;
}
