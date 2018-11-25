#pragma once
class Order;
class Stock;
class Ctest3Dlg;
class Sales;
class Setting
{
public:
	Setting(Ctest3Dlg*);
	~Setting();
	Order *order[50];
	Stock *stock;
	Sales *sales;
	Ctest3Dlg *p_mainFrm;
	int count;
	
	void AddMenu(CString name);
	int GetSum();
	
};

