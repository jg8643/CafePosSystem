#include "stdafx.h"
#include "afxdialogex.h"
#include "Stock.h"
#include "order.h"
#include <stdio.h>
#include "test3Dlg.h"
#include "Setting.h"

// 생성자
Stock::Stock(Setting* set) {
	this->set  = set;
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	coffee_count = 0;
	juice_count = 0;
	bread_count = 0;
	count = 0;
	ReadStockFile();
}

// 파일 읽기
void Stock::ReadStockFile() {
	char buf[50];
	char *temp[4];
	FILE *fin = fopen("stock.txt", "r");


	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 4; i++) {
			// "ㅣ" 기준으로 단어 나누기
			temp[i] = strtok(NULL, "|");
		}
		menu[count++] = new Order(temp[0], temp[1], temp[2], temp[3]);
	}
	
	fclose(fin);

	// 탭 마다 몇개 씩 생성되는가 체크하기 위해서
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

// 파일 쓰기
/*
CStringA 는 CString 에서 Char* 로 형변환을 위해 사용
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

// 메뉴 추가
void Stock::AddMenu(CString *str)
{
	// 메뉴 생성
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

// 메뉴 삭제
void Stock::DeleteMenu(CListCtrl *m_listctrl)
{
	int mark = m_listctrl->GetSelectionMark();

	if (mark >= 0) {
		for (int i = 0; i < set->stock->count; i++) {
			if (m_listctrl->GetItemText(mark, 0) == set->stock->menu[i]->name) {
				if (set->stock->menu[i]->tab == L"커피")
					set->stock->coffee_count--;
				else if (set->stock->menu[i]->tab == L"음료")
					set->stock->juice_count--;
				else
					set->stock->bread_count--;

				// 끌어 올리기
				for (int j = i; j < set->stock->count; j++) {
					set->stock->menu[j] = set->stock->menu[j + 1];
				}
				set->stock->count = set->stock->count - 1;
			}

		}
		m_listctrl->DeleteItem(mark);
	}
	else
		AfxMessageBox(L"삭제할 메뉴를 선택해주세요.");
}

// 받아온 이름과 재고파일의 이름을 비교후 같다면 재고파일의 index 반환
int Stock::SearchName(CString name) {
	for (int i = 0; i < count; i++) {
		if (menu[i]->name == name) {
			return i;
		}
	}
	return -1;
}