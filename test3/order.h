#pragma once

// 메뉴이름, 개수, 가격 저장

class Order
{
public:
	// 생성자
	Order(CString, int, int); 
	Order(char *, char *, char *, char *r);  // 재고관리용 생성자
	Order(CString *);
	// 필드

	CString tab;
	CString name;
	int number;
	int price;

	// 메소드
	CString GetPrice();
	CString GetNumber();
};

