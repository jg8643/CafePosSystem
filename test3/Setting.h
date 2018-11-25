#pragma once
class Order;
class Stock;
class SalesData;
class Ctest3Dlg;
class Setting
{
public:
	Setting(Ctest3Dlg*);
	~Setting();
	Order *order[50];
	Stock *stock;
	SalesData *s_data;
	Ctest3Dlg *p_mainFrm;
	int count;
	
	void AddMenu(CString name);
	int GetSum();
	
};

