#include "order.h"
#include "test3Dlg.h"
class Stock
{
public:
	Stock();

	int i_count;
	int count; //메뉴 개수
	Order *menu[50];
	Ctest3Dlg *ptest3Dlg;
	int coffee_count;
	int juice_count;
	int bread_count;

	void AddMenu(CString *);
	void ChangeStock();
	void ReadStockFile();
	void WriteStockFile();
	int SearchName(CString);
};
