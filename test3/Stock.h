#include "order.h"
#include "test3Dlg.h"
#include "Setting.h"
class Stock
{
public:
	Stock(Setting *);  // ������

	int i_count;    // ��� ����(Cinventory) ���� ��� ����� ���� Ŭ�� ���� ���� index �����
	int count; // �޴� ����
	Order *menu[50];
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
	int coffee_count;  // Ŀ�� �� �޴� ����
	int juice_count;   // ���� �� �޴� ����
	int bread_count;   // ����Ŀ�� �� �޴� ����

	void AddMenu(CString *);       // �޴� �߰�
	void DeleteMenu(CListCtrl *);  // �޴� ����
	void ReadStockFile();          // ������� �б�
	void WriteStockFile();         // ������� ����
	int SearchName(CString);       // ��������� �̸� �񱳿�
};
