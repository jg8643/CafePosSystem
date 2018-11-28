#include "stdafx.h"
#include "afxdialogex.h"
#include "Stock.h"
#include "order.h"
#include <stdio.h>
#include "test3Dlg.h"
#include "Setting.h"

// ������
Stock::Stock(Setting* set) {
	this->set  = set;
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	coffee_count = 0;
	juice_count = 0;
	bread_count = 0;
	count = 0;
	ReadStockFile();
}

// ���� �б�
void Stock::ReadStockFile() {
	char buf[50];
	char *temp[4];
	FILE *fin = fopen("stock.txt", "r");


	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 4; i++) {
			// "��" �������� �ܾ� ������
			temp[i] = strtok(NULL, "|");
		}
		menu[count++] = new Order(temp[0], temp[1], temp[2], temp[3]);
	}
	
	fclose(fin);

	// �� ���� � �� �����Ǵ°� üũ�ϱ� ���ؼ�
	for (int i = 0; i < count; i++) {
		if (menu[i]->tab == L"Ŀ��") {
			coffee_count++;
		}
		else if (menu[i]->tab == L"����") {
			juice_count++;
		}
		else {
			bread_count++;
		}
	}
}

// ���� ����
/*
CStringA �� CString ���� Char* �� ����ȯ�� ���� ���
*/
void Stock::WriteStockFile()
{
	FILE *fout = fopen("stock.txt", "w+");
	for (int i = 0; i < count-1; i++) {
		CStringA charstr1(menu[i]->tab);
		CStringA charstr2(menu[i]->name);
		fprintf(fout, "%s%d%s%d\n",charstr1+"|"+charstr2+"|", menu[i]->number,"|", menu[i]->price);
	}
	CStringA charstr1(menu[count-1]->tab);
	CStringA charstr2(menu[count-1]->name);
	fprintf(fout, "%s%d%s%d", charstr1 + "|" + charstr2 + "|", menu[count-1]->number, "|", menu[count-1]->price);
	fclose(fout);
}

// �޴� �߰�
void Stock::AddMenu(CString *str)
{
	// �޴� ����
	menu[count] = new Order(str);

	if (str[0] == L"Ŀ��") {
		coffee_count++;
	}
	else if (str[0] == L"����") {
		juice_count++;
	}
	else {
		bread_count++;
	}
	count++;
	WriteStockFile();
}

// �޴� ����
void Stock::DeleteMenu(CListCtrl *m_listctrl)
{
	int mark = m_listctrl->GetSelectionMark();

	if (mark >= 0) {
		for (int i = 0; i < set->stock->count; i++) {
			if (m_listctrl->GetItemText(mark, 0) == set->stock->menu[i]->name) {
				if (set->stock->menu[i]->tab == L"Ŀ��")
					set->stock->coffee_count--;
				else if (set->stock->menu[i]->tab == L"����")
					set->stock->juice_count--;
				else
					set->stock->bread_count--;

				// ���� �ø���
				for (int j = i; j < set->stock->count; j++) {
					set->stock->menu[j] = set->stock->menu[j + 1];
				}
				set->stock->count = set->stock->count - 1;
			}

		}
		m_listctrl->DeleteItem(mark);
	}
	else
		AfxMessageBox(L"������ �޴��� �������ּ���.");
}

// �޾ƿ� �̸��� ��������� �̸��� ���� ���ٸ� ��������� index ��ȯ
int Stock::SearchName(CString name) {
	for (int i = 0; i < count; i++) {
		if (menu[i]->name == name) {
			return i;
		}
	}
	return -1;
}