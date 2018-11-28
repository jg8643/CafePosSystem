#pragma once
class Ctest3Dlg;
class SalesData {
public:
	SalesData(char*, char*, char*, char*);       // s_data ������ ���
	SalesData(int, CString, CString, CString);   // ��� �� �������� ���� ���� ���
	SalesData(CString, int, int);                // t_data ������ ���

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
	
	SalesData *s_data[1024];   // ���� ������ �о ����
	SalesData *t_data[1024];   // ���� ��� �κп��� �������Ͽ��� �ߺ��κ��� ����
	Ctest3Dlg *ptest3Dlg;
	int count;              // ���������� ��� ����
	int t_count;            // t_data�� ��� ����

	void SetTdata(CString, CString);     // t_data ����
	void ReadSalesFile();                // �������� �б�
	void WriteSalesFile();               // �������� ����
	void InitTdata();                    // t_data �ʱ�ȭ
	int startpos(int, int);              // �������ϰ� ��¥�� ���� ���� �κ��� �������� �ε��� ��ȯ
	int AddDate();                       // ��¥ ������
	int SearchFile();                    // s_data�� ��¥�� ���� ��¥�� ������ �ε��� ��ȯ
	void ChangeSales();                  // ��� �� �������� ����
};