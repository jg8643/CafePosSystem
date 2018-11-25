#include "stdafx.h"
#include "afxdialogex.h"
#include "Stock.h"
#include "order.h"
#include <stdio.h>
#include "test3Dlg.h"
Stock::Stock() {
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd;
	coffee_count = 0;
	juice_count = 0;
	bread_count = 0;
	count = 0;
	ReadStockFile();
}


void Stock::ReadStockFile() {
	char buf[50];
	char *temp[4];
	FILE *fin = fopen("stock.txt", "r");

	int i = 1;

	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		fprintf(stdout, "%03d : %s",i++, buf);

		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 4; i++) {
			temp[i] = strtok(NULL, "|");
		}
		menu[count++] = new Order(temp[0], temp[1], temp[2], temp[3]);
	}

	fclose(fin);
	for (int i = 0; i < count; i++) {
		if (menu[i]->tab == L"커피") {
			coffee_count++;
		}
		else if (menu[i]->tab == L"음료") {
			juice_count++;
		}
		else {
			bread_count++;
		}
	}
}
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


void Stock::AddMenu(CString *str)
{
	menu[count] = new Order(str);
	if (str[0] == L"커피") {
		coffee_count++;
	}
	else if (str[0] == L"음료") {
		juice_count++;
	}
	else {
		bread_count++;
	}
	count++;
	WriteStockFile();
}
int Stock::SearchName(CString name) {

	for (int i = 0; i < count; i++) {
		if (menu[i]->name == name) {
			return i;
		}
	}

	return -1;
}
void Stock::ChangeStock()
{
	int num = ptest3Dlg->m_listctrl.GetItemCount();
	for (int i = 0; i < ptest3Dlg->m_listctrl.GetItemCount(); i++) {
		for (int j = 0; j < count; j++) {
			if (ptest3Dlg->m_listctrl.GetItemText(i, 0) == menu[j]->name) {
				menu[j]->number = menu[j]->number - _ttoi(ptest3Dlg->m_listctrl.GetItemText(i, 1));
				break;
			}
		}
	}
	WriteStockFile();
}