#include "22100487_이경민_product.h"

void Clear(void)
{
	while (getchar() != '\n');
}

int selectProduct()
{
	int menu;
	printf("\n");
	printf("1. 제품 추가\n");
	printf("2. 제품 조회\n");
	printf("3. 제품 수정\n");
	printf("4. 제품 삭제\n");
	printf("5. 제품 저장\n");
	printf("6. 제품 검색\n");
	printf("0. 종료\n");
	printf("\n=> 원하는 항목 : ");
	scanf("%d", &menu);
	printf("\n");

	return menu;
}

int plusProduct(struct food_struct *p, int number)
{
	printf("제품명 : ");
	scanf("%[^\n]s", p->name);
	getchar();
	printf("중량 : ");
	scanf("%s", p->weight);
	printf("판매가격 : ");
	scanf("%d", &p->price);
	printf("배송방법(1: 새벽배송/2: 택배배송) : ");
	scanf("%d", &p->way);
	printf("=> 추가되었습니다.\n");

	return number + 1;
}

void readProduct(struct food_struct *p, int number)
{
	printf("\n================================================================\n");
	printf("NO.		제품명         중량    판매가격  배송방법\n");
	printf("----------------------------------------------------------------\n");
	printf("%d.	    %-20s   %-5s     %-5d      %d\n", number, p->name, p->weight, p->price, p->way);
}

int updateProduct(struct food_struct *p, int number)
{
	int flag;
	printf("수정할 번호 (0 : 취소) : ");
	scanf("%d", &flag);
	Clear();
	if (flag == 0)
		return number;
	else
	{
		printf("제품명 : ");
		scanf("%[^\n]", p->name);
		getchar();
		printf("중량 : ");
		scanf("%s", p->weight);
		getchar();
		printf("판매가격 : ");
		scanf("%d", &p->price);
		printf("배송방법(1: 새벽배송/2: 택배배송) : ");
		scanf("%d", &p->way);

		printf("=> 수정되었습니다.\n");
	}

	return number;
}

int deleteProduct(struct food_struct *p, int number)
{
	int index;
	printf("삭제할 번호 (0 : 취소) : ");
	scanf("%d", &index);
	if (index == 0)
		return number - 1;
	else
	{
		for (int i = index - 1; i < number; i++)
		{
			p[i] = p[i + 1];
		}
		printf("=> 삭제되었습니다\n");
	}

	return number - 1;
}

void saveProduct(struct food_struct *p, int number)
{
	FILE *fp = fopen("product.txt", "w");

	for (int i = 0; i < number; i++)
	{
		fprintf(fp, "%s %s %d %d\n", p->name, p->weight, p->price, p->way);
	}

	fclose(fp);
	printf("=> 저장되었습니다.\n");
}

void searchProduct(struct food_struct *p, int number)
{
	int count = 0;
	char search[100];

	printf("검색할 제품? ");
	scanf("%[^\n]", search);
	getchar();

	for (int i = 0; i < number; i++)
	{
		if (strstr(p->name, search))
		{
			printf("\n================================================================\n");
			printf("제품명            중량	   판매가격  배송방법\n");
			printf("----------------------------------------------------------------\n");
			printf("%-20s   %-5s     %-5d      %d\n\n", p->name, p->weight, p->price, p->way);
		}
	}
}

int loadData(struct food_struct *p)
{
	FILE *fp = fopen("product.txt", "r");

	if (fp != NULL)
	{
		fscanf(fp, "%s %s %d %d\n", p->name, p->weight, &p->price, &p->way);
		fclose(fp);
		printf("=> 로딩 성공!\n");
		return 1;
	}
	else
		printf("=> 파일 없음\n");

	return 0;
}