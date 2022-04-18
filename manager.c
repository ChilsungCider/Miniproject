#include "manager.h"

void Clear(void) // 입력버퍼 없애기 
{
	while (getchar() != '\n')
		;
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
	printf("0. 제품 종료\n");
	printf("\n=> 원하는 항목 : ");
	scanf("%d", &menu);
	printf("\n");

	return menu;
}

int plusProduct(struct food_struct *p[], int number) // 추가기능
{
	p[number] = (struct food_struct *)malloc(sizeof(struct food_struct));
	printf("제품명 : ");
	scanf("%[^\n]", p[number]->name);
	getchar();
	printf("중량 : ");
	scanf("%s", p[number]->weight);
	printf("판매가격 : ");
	scanf("%d", &p[number]->price);
	printf("배송방법(1: 새벽배송/2: 택배배송) : ");
	scanf("%d", &p[number]->way);
	printf("=> 추가되었습니다.\n");

	return number + 1;
}

void readProduct(struct food_struct *p[], int number) // 조회
{
	printf("\n================================================================\n");
	printf("NO.		제품명         중량    판매가격  배송방법\n");
	printf("----------------------------------------------------------------\n");
	for (int i = 0; i < number; i++)
	{
		printf("%d.	    %-20s   %-5s     %-5d      %d\n", i + 1, p[i]->name, p[i]->weight, p[i]->price, p[i]->way);
	}
}

int updateProduct(struct food_struct *p[], int number) // 수정기능
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
		scanf("%[^\n]", p[flag - 1]->name);
		getchar();
		printf("중량 : ");
		scanf("%s", p[flag - 1]->weight);
		getchar();
		printf("판매가격 : ");
		scanf("%d", &p[flag - 1]->price);
		printf("배송방법(1: 새벽배송/2: 택배배송) : ");
		scanf("%d", &p[flag - 1]->way);

		printf("=> 수정되었습니다.\n");
	}

	return number;
}

int deleteProduct(struct food_struct *p[], int number) // 삭제기능
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

void saveProduct(struct food_struct *p[], int number) // 파일로 저장기능
{
	FILE *fp = fopen("product.txt", "w");

	for (int i = 0; i < number; i++)
	{
		fprintf(fp, "%s\n%s\n%d\n%d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->way);
	}
	fclose(fp);
	printf("=> 저장되었습니다.\n");
}

void searchProduct1(struct food_struct *p[], int number) // 검색기능1 (제품명)
{
	char search[100];

	printf("\n검색할 제품? ");
	scanf("%[^\n]", search);
	printf("\n");

	for (int i = 0; i < number; i++)
	{
		if (strstr(p[i]->name, search))
		{
			printf("\n================================================================\n");
			printf("제품명            중량	   판매가격  배송방법\n");
			printf("----------------------------------------------------------------\n");
			printf("%-20s  %-5s     %-5d       %d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->way);
		}
	}
	printf("\n");
}

void searchProduct2(struct food_struct *p[], int number) // 검색기능2 (배송방법) 
{
	int search = 0;
	printf("\n검색할 배송방법 ? ");
	scanf("%d", &search);

	for (int i = 0; i < number; i++)
	{
		if (p[i]->way == search)
		{
			printf("\n================================================================\n");
			printf("제품명            중량	   판매가격  배송방법\n");
			printf("----------------------------------------------------------------\n");
			printf("%-20s  %-5s     %-5d       %d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->way);
		}
	}
	printf("\n");
}

void searchProduct3(struct food_struct *p[], int number) // 검색기능3 (가격)
{
	int min_pay = 0, max_pay = 0;

	printf("\n최소 가격 : ");
	scanf("%d", &min_pay);
	printf("최대 가격 : ");
	scanf("%d", &max_pay);
	
	for (int i = 0; i < number; i++)
	{
		if (min_pay <= p[i]->price && max_pay >= p[i]->price)
		{	
			printf("\n================================================================\n");
			printf("제품명            중량	   판매가격  배송방법\n");
			printf("----------------------------------------------------------------\n");
			printf("%-20s  %-5s     %-5d       %d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->way);
		}
	}
}

int loadData(struct food_struct *p[], int number) // 파일 불러오기
{
	int count = 0;
	FILE *fp = fopen("product.txt", "r");

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			p[count] = (struct food_struct *)malloc(sizeof(struct food_struct));
			int ret = fscanf(fp, "%[^\n]\n%s\n%d\n%d\n", p[count]->name, p[count]->weight, &p[count]->price, &p[count]->way);
			if (ret < 2)
				continue;
			count++;
		}
		fclose(fp);
		printf("=> 로딩 성공!\n");
		return count;
	}
	else
	{
		printf("=> 파일 없음\n");
	}

	return count;
}
