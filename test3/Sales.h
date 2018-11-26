#pragma once
class Ctest3Dlg;
class SalesData {
public:
	SalesData(char*, char*, char*, char*);
	SalesData(int, CString, CString, CString);
	SalesData(CString, int, int);
	int date;
	CString name;
	int number;
	int price;
	CString GetNumber();
	CString GetPrice();
};
class Sales {
public:
	Sales();
	int count;
	int t_count;
	SalesData *s_data[1024];
	SalesData *t_data[1024];
	Ctest3Dlg *ptest3Dlg;

	void ReadSalesFile();
	void WriteSalesFile();
	void SetTdata(CString, CString);
	void InitTdata();
	int startpos(int, int);
	int AddDate();
	int SearchFile();
	void ChangeSales();
};