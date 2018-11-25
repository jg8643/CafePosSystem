#pragma once
class Ctest3Dlg;
class SalesData;
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