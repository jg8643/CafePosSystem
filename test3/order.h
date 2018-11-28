#pragma once

// 메뉴이름, 개수, 가격 저장

class Order
{
public:
	Order(CString, int, int); // 주문 목록에 메뉴 처음 생성 할때 사용
	Order(char *, char *, char *, char *r);  // 재고파일에서 데이터를 읽고 재고파일의 menu 생성시 사용
	Order(CString *);// 메뉴 추가 할 때 사용하는 생성자


	CString tab;
	CString name;
	int number;
	int price;


	CString GetTotalPrice();  // number * price   int to CString
	CString GetPrice();       // price    int to CString
	CString GetNumber();      // number   int to CString
};

