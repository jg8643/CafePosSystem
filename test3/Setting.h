#pragma once
class Order;
class Stock;
class Ctest3Dlg;
class Sales;
class Setting
{
public:
	Setting(Ctest3Dlg*);
	~Setting();
	Order *order[50];  // 주문 메뉴
	Stock *stock;      // 재고 담당
	Sales *sales;      // 매출 담당
	int count;         // 주문 메뉴 개수
	
	int GetSum();      // 합계
	void AddMenu(CString name);  // 탭 에서 선택된 메뉴를 주문목록 리스트컨트롤에 추가

	
};

