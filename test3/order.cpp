#include "stdafx.h"
#include "order.h"
#include <stdlib.h>



Order::Order(CString name, int number, int price)
{
	this->name = name;
	this->number = number;
	this->price = price;
}

// 犁绊包府侩 积己磊
Order::Order(char *tab, char *name, char *number, char *price)  
{
	this->tab = tab;
	this->name = name;
	this->number = atoi(number);
	this->price = atoi(price);
}

Order::Order(CString *str)
{
	this->tab = str[0];
	this->name = str[1];
	this->number = _ttoi(str[2]);
	this->price = _ttoi(str[3]);
}

// price   int to CString
CString Order::GetTotalPrice() {
	CString str;
	str.Format(L"%d",price*number);
	return str;
}

CString Order::GetPrice()
{
	CString str;
	str.Format(L"%d", price);
	return str;
}

// number  int to CString
CString Order::GetNumber() {
	CString str;
	str.Format(L"%d", number);
	return str;
}
