#pragma once
class Ctest3Dlg;
class SalesData {
public:
	SalesData(char* date, char* name, char* number, char* price);
	SalesData(int date, CString name, CString number, CString price);

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
	SalesData *s_data[1024];
	Ctest3Dlg *ptest3Dlg;

	void ReadSalesFile();
	void WriteSalesFile();
	int AddDate();
	void ChangeSales();
};