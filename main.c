#include "manager.h"

int main()
{
	struct food_struct *Product[20];
	int number = 0;
	int menu, search = 0;

	number = loadData(Product);

	while (1)
	{
		menu = selectProduct();
		Clear();
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
		{
			while (1)
			{
				printf("기능(1:이름, 2:배송방법, 3:가격) : ");
				scanf("%d", &search);
				if (search == 1)
				{
					Clear();
					searchProduct1(Product, number);
					break;
				}
				else if (search == 2)
				{
					searchProduct2(Product, number);
					break;
				}
				else if (search == 3)
				{
					searchProduct3(Product, number);
					break;
				}
				else
				{
					printf("기능(1:이름, 2:가격, 3:배송방법) : ");
					scanf("%d", &search);
				}
			}
		}
	}
	printf("=> 종료\n");

	free(*Product);
	return 0;
}
