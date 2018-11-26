#include "stdafx.h"
#include "afxdialogex.h"
#include "Sales.h"
#include <time.h>
#include "test3Dlg.h"
#include "Setting.h"

SalesData::SalesData(char* date, char* name, char* number, char* price) {
	this->date = atoi(date);
	this->name = name;
	this->number = atoi(number);
	this->price = atoi(price);
};
SalesData::SalesData(int date, CString name, CString number, CString price) {
	this->date = date;
	this->name = name;
	this->number = _ttoi(number);
	this->price = _ttoi(price);
}
SalesData::SalesData(CString name, int number, int price)
{
	this->name = name;
	this->number = number;
	this->price = price;
}
CString SalesData::GetNumber()
{
	CString str;
	str.Format(L"%d", number);
	return str;
}
CString SalesData::GetPrice()
{
	CString str;
	str.Format(L"%d", price);
	return str;
}
;

Sales::Sales() {
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	count = 0;
	t_count = 0;
	ReadSalesFile();
}
void Sales::ReadSalesFile()
{
	char buf[50];
	char *temp[4];
	FILE *fin = fopen("Sales.txt", "r");

	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 4; i++) {
			temp[i] = strtok(NULL, "|");
		}
		s_data[count++] = new SalesData(temp[0], temp[1], temp[2], temp[3]);
	}
	fclose(fin);
}

void Sales::WriteSalesFile()
{
	FILE *fout = fopen("Sales.txt", "w+");
	for (int i = 0; i < count - 1; i++) {
		CStringA charstr1(s_data[i]->name);
		fprintf(fout, "%d|%s|%d|%d\n", s_data[i]->date, charstr1, s_data[i]->number, s_data[i]->price);
	}
	CStringA charstr1(s_data[count -1]->name);
	fprintf(fout, "%d|%s|%d|%d", s_data[count -1]->date, charstr1, s_data[count - 1]->number, s_data[count - 1]->price);
	fclose(fout);
}

void Sales::SetTdata(CString str1, CString str2)
{
	int i = 0, f_count = 0;
	int	temp;
	i = startpos(i, _ttoi(str1));
	temp = _ttoi(str2)+1;

	while (s_data[i]->date != temp) {
		if (t_count == 0) {
			// 처음 생성
			t_data[t_count] = new SalesData(s_data[i]->name, s_data[i]->number, s_data[i]->price);
			t_count++;
			i++;
		}
		else {
			// 처음이 아닐 때
			for (int j = 0; j < t_count; j++) {
				if (&s_data[i]->date == NULL)
					break;
				if (s_data[i]->date == temp)
					break;
				for (int k = 0; k < count; k++) {
					if (f_count == 1)  // 이미 만들었으면 탈출
						break;
					if (&t_data[k]->date == NULL) //다음게 존재하지 않으면 탈출
						break;
					if (t_data[k]->name == s_data[i]->name) {
						// s_data의 이름과 t_data의 이름이 같으면 개수, 가격 수정
						t_data[k]->price = t_data[k]->price / t_data[k]->number * (t_data[k]->number + s_data[i]->number);
						t_data[k]->number += s_data[i]->number;
						f_count = 1;
						i++;
						break;
					}
				}
				if (f_count == 0) {
					// s_data의 이름과 t_data의 이름이 같지 않아 새로 생성
					t_data[t_count] = new SalesData(s_data[i]->name, s_data[i]->number, s_data[i]->price);
					t_count++;
					i++;
					break;
				}
				f_count = 0;
			}
		}
		if (&s_data[i]->date == NULL)
			break;
	}
}

void Sales::InitTdata()
{
	for (int k = 0; k < t_count; k++) {
		t_data[k] = NULL;
	}
	t_count = 0;
}

int Sales::startpos(int index, int str)
{

	for (int i = 0; i < count; i++) {
		if (s_data[i]->date == str) {
			index = i;
			break;
		}
		else
			index = 0;
	}
	return index;
}

int Sales::AddDate()
{
	int result;
	struct tm *datetime;
	time_t t;
	char buf[100];
	int year, month, day, hour, min, sec;

	t = time(NULL);
	datetime = localtime(&t);

	year = datetime->tm_year + 1900;
	month = datetime->tm_mon + 1;
	day = datetime->tm_mday;
	hour = datetime->tm_hour;
	min = datetime->tm_min;
	sec = datetime->tm_sec;

	sprintf(buf, "%d%d%d", year, month, day);
	result = atoi(buf);
	return result;
}

int Sales::SearchFile()
{
	int result = 0;
	int today = AddDate();

	for (int i = 0; i < count; i++) {
		if (s_data[i]->date == today) {
			result = i;
			break;
		}
		else
			result = i + 1;
	}
	return result;
}

void Sales::ChangeSales()
{
	int f_count = 0;
	int i = 0;
	int j;
	int start_point = SearchFile();
	int num = ptest3Dlg->m_listctrl.GetItemCount();
	while (i != num) {

		if (&s_data[start_point]->date == NULL) {
			// 날짜 바뀌고 처음 쓸때
			for (int k = start_point; k < (start_point + num ); k++) {
				s_data[k] = new SalesData(AddDate(), ptest3Dlg->m_listctrl.GetItemText(i, 0), ptest3Dlg->m_listctrl.GetItemText(i, 1), ptest3Dlg->m_listctrl.GetItemText(i, 2));
				count++;
				i++;
			}
			break;
		}
		
		for (start_point; start_point < count; start_point++) {
			if (ptest3Dlg->m_listctrl.GetItemText(i, 0) == s_data[start_point]->name) {
				s_data[start_point]->price = s_data[start_point]->price / s_data[start_point]->number * (s_data[start_point]->number + _ttoi(ptest3Dlg->m_listctrl.GetItemText(i, 1)));
				s_data[start_point]->number += _ttoi(ptest3Dlg->m_listctrl.GetItemText(i, 1));
				f_count = 1;
				start_point = SearchFile();
				break;
			}
		}
		if (f_count == 0) {
			s_data[start_point] = new SalesData(AddDate(), ptest3Dlg->m_listctrl.GetItemText(i, 0), ptest3Dlg->m_listctrl.GetItemText(i, 1), ptest3Dlg->m_listctrl.GetItemText(i, 2));
			count++;
		}
		f_count = 0;
		i++;
		start_point = SearchFile();
	}
	WriteSalesFile();
}
