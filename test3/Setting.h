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
	Order *order[50];  // �ֹ� �޴�
	Stock *stock;      // ��� ���
	Sales *sales;      // ���� ���
	int count;         // �ֹ� �޴� ����
	
	int GetSum();      // �հ�
	void AddMenu(CString name);  // �� ���� ���õ� �޴��� �ֹ���� ����Ʈ��Ʈ�ѿ� �߰�

	
};

