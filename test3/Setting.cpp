#include "stdafx.h"
#include "Setting.h"
#include "order.h"
#include "test3Dlg.h"
#include "Stock.h"
#include <String.h>

Setting::Setting(Ctest3Dlg* p_mainFrm)
{	
	count = 0;
	this->p_mainFrm = p_mainFrm;
	stock = new Stock(this);
}

Setting::~Setting()
{
}

void Setting::AddMenu(CString name) {

	int index = stock->SearchName(name);

	// 메뉴의 재고가 없을 때
	if (index == -1) {
		return;
	}


	index = -1;
	for (int i = 0; i < count; i++) {
		if (order[i]->name == name) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		for (int i = 0; i < stock->count; i++) {
			if (stock->menu[i]->name == name)
				order[count++] = new Order(name, 1, stock->menu[i]->price);
		}
	}
	else {
		order[index]->number++;
	}
}

int Setting::GetSum() {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += order[i]->number * order[i]->price
;
	}

	return sum;
}
