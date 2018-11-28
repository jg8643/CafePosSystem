#include "stdafx.h"
#include "Setting.h"
#include "order.h"
#include "test3Dlg.h"
#include "Stock.h"
#include "Sales.h"
#include <String.h>

Setting::Setting(Ctest3Dlg* p_mainFrm)
{	
	count = 0;
	stock = new Stock(this);
	sales = new Sales();

}

Setting::~Setting()
{
}

void Setting::AddMenu(CString name) {
	int index = -1;
	
	// 현재 주문 목록 중에서 같은 이름이 존재 하는지 확인하기 위해
	for (int i = 0; i < count; i++) {
		if (order[i]->name == name) {
			index = i;
			break;
		}
	}
	// -1 이면 현재 주문 목록 중에서는 같은 이름이 없으니 새로 생성
	if (index == -1) {
		for (int i = 0; i < stock->count; i++) {
			if (stock->menu[i]->name == name) {
				order[count++] = new Order(name, 1, stock->menu[i]->price);
				stock->menu[i]->number--;
			}
		}
	}
	// -1이 아니면 현재 주문목록에 같은이름이 존재함으로 개수를 추가
	else {
		order[index]->number++;
		for (int i = 0; i < stock->count; i++) {
			// 주문 목록에 개수를 추가 시 재고파일 개수 재정리
			if (order[index]->name == stock->menu[i]->name) {
				stock->menu[i]->number--;
			}
		}
	}
}

int Setting::GetSum() {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += order[i]->number * order[i]->price;
	}
	return sum;
}
