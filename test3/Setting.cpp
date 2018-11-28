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
	
	// ���� �ֹ� ��� �߿��� ���� �̸��� ���� �ϴ��� Ȯ���ϱ� ����
	for (int i = 0; i < count; i++) {
		if (order[i]->name == name) {
			index = i;
			break;
		}
	}
	// -1 �̸� ���� �ֹ� ��� �߿����� ���� �̸��� ������ ���� ����
	if (index == -1) {
		for (int i = 0; i < stock->count; i++) {
			if (stock->menu[i]->name == name) {
				order[count++] = new Order(name, 1, stock->menu[i]->price);
				stock->menu[i]->number--;
			}
		}
	}
	// -1�� �ƴϸ� ���� �ֹ���Ͽ� �����̸��� ���������� ������ �߰�
	else {
		order[index]->number++;
		for (int i = 0; i < stock->count; i++) {
			// �ֹ� ��Ͽ� ������ �߰� �� ������� ���� ������
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
