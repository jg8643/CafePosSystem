#include "stdafx.h"
#include "afxdialogex.h"
#include "Sales.h"
#include <time.h>
#include "test3Dlg.h"

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
	FILE *fout = fopen("Sales1.txt", "w+");
	for (int i = 0; i < count - 1; i++) {
		CStringA charstr1(s_data[i]->name);
		fprintf(fout, "%d|%s|%d|%d\n", s_data[i]->date, charstr1, s_data[i]->number, s_data[i]->price);
	}
	CStringA charstr1(s_data[count -1]->name);
	fprintf(fout, "%d|%s|%d|%d", s_data[count -1]->date, charstr1, s_data[count - 1]->number, s_data[count - 1]->price);
	fclose(fout);
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

void Sales::ChangeSales()
{
	int f_count = 0;
	int j;
	int num = ptest3Dlg->m_listctrl.GetItemCount();
	for (int i = 0; i < num; i++) {

		for (j = 0; j < count; j++) {
			if (f_count == 1)
				break;
			////////////////////////////////////
			if (ptest3Dlg->m_listctrl.GetItemText(i, 0) == s_data[j]->name) {
				s_data[j]->price = s_data[j]->price / s_data[j]->number * (s_data[j]->number + _ttoi(ptest3Dlg->m_listctrl.GetItemText(i, 1)));
				s_data[j]->number += _ttoi(ptest3Dlg->m_listctrl.GetItemText(i, 1));
				f_count = 1;
			}
		}

		if (f_count == 0) {
			s_data[j] = new SalesData(AddDate(), ptest3Dlg->m_listctrl.GetItemText(i, 0), ptest3Dlg->m_listctrl.GetItemText(i, 1), ptest3Dlg->m_listctrl.GetItemText(i, 2));
			count++;
		}
		f_count = 0;
	}
	WriteSalesFile();
}
