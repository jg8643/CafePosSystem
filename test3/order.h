#pragma once

// �޴��̸�, ����, ���� ����

class Order
{
public:
	Order(CString, int, int); // �ֹ� ��Ͽ� �޴� ó�� ���� �Ҷ� ���
	Order(char *, char *, char *, char *r);  // ������Ͽ��� �����͸� �а� ��������� menu ������ ���
	Order(CString *);// �޴� �߰� �� �� ����ϴ� ������


	CString tab;
	CString name;
	int number;
	int price;


	CString GetTotalPrice();  // number * price   int to CString
	CString GetPrice();       // price    int to CString
	CString GetNumber();      // number   int to CString
};

