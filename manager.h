#ifndef _MANAGER_C
#define _MANAGER_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct food_struct
{
	char name[20];	   //제품 명
	char explain[100]; // 제품의 설명
	char weight[20];   // 제품의 양 (ex: 100g, 10개입, 1봉지)
	int price;		   // 제품의 가격
	int way;		   // 1: 새벽배송, 2: 택배배송
} Product;

int plusProduct(struct food_struct *p[], int number);	// 제품 추가 함수 (제품 추가)
int updateProduct(struct food_struct *p[], int number); // 제품 수정 함수 (제품 수정)
int deleteProduct(struct food_struct *p[], int number); // 제품 삭제 함수 (제품 삭제)
int loadData(struct food_struct *p[]);
void readProduct(struct food_struct *p[], int number);	 // 전체 제품 출력 함수 (제품 조회)
void saveProduct(struct food_struct *p[], int number);	 // 파일 저장 함수 (제품 저장)
void searchProduct1(struct food_struct *p[], int number); // 검색기능1 (제품명)
void searchProduct2(struct food_struct *p[], int number); // 검색기능2 (배송방법)
void searchProduct3(struct food_struct *p[], int number); // 검색기능3 (가격)
int selectProduct();
void Clear(void);

#endif
