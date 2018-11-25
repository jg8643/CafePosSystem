#pragma once
class Order;
class Stock;
class SalesData;
class Setting
{
public:
	Setting();
	~Setting();
	Order *order[50];
	Stock *stock;
	SalesData *s_data;
	int count;
	
	void AddMenu(CString name);
	int GetSum();
	
};

