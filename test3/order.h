#pragma once

// �޴��̸�, ����, ���� ����

class Order
{
public:
	// ������
	Order(CString, int, int); 
	Order(char *, char *, char *, char *r);  // �������� ������
	Order(CString *);
	// �ʵ�

	CString tab;
	CString name;
	int number;
	int price;

	// �޼ҵ�
	CString GetPrice();
	CString GetNumber();
};

