#include "order.h"
#include "test3Dlg.h"
#include "Setting.h"
class Stock
{
public:
	Stock(Setting *);  // 생성자

	int i_count;    // 재고 관리(Cinventory) 에서 재고 목록을 더블 클릭 했을 때의 index 저장용
	int count; // 메뉴 개수
	Order *menu[50];
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
	int coffee_count;  // 커피 탭 메뉴 개수
	int juice_count;   // 음료 탭 메뉴 개수
	int bread_count;   // 베이커리 탭 메뉴 개수

	void AddMenu(CString *);       // 메뉴 추가
	void DeleteMenu(CListCtrl *);  // 메뉴 삭제
	void ReadStockFile();          // 재고파일 읽기
	void WriteStockFile();         // 재고파일 쓰기
	int SearchName(CString);       // 재고파일의 이름 비교용
};
