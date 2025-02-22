// CTab2.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CTab2.h"
#include "afxdialogex.h"
#include "test3Dlg.h"
#include "order.h"
#include "Setting.h"
#include "Stock.h"
// CTab2 대화 상자

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)

CTab2::CTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, menulistctrl);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CTab2::OnNMDblclkList1)
END_MESSAGE_MAP()


// CTab2 메시지 처리기

// juice_count 만큼 이미지 리스트 셋팅
void CTab2::MenuSetting() {
	CBitmap bmp;
	int count = 0;
	bmp.LoadBitmap(IDB_BITMAP2);

	imglist.Create(72, 72, ILC_COLOR32, set->stock->juice_count, 0);

	Add();
}

// 음료 탭에 메뉴 버튼 생성
void CTab2::Add() {
	CBitmap bmp;
	int count = 0;
	bmp.LoadBitmap(IDB_BITMAP2);

	imglist.Add(&bmp, RGB(0, 0, 0));
	menulistctrl.SetImageList(&imglist, LVSIL_NORMAL);

	menulistctrl.DeleteAllItems();
	for (int i = 0; i < set->stock->count; i++) {
		if (set->stock->menu[i]->tab == L"음료") {
			menulistctrl.InsertItem(count++, set->stock->menu[i]->name);
		}
	}
}
BOOL CTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MenuSetting();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CTab2::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int s_count = 0;

	for (int i = 0; i < menulistctrl.GetItemCount(); i++){
		if (menulistctrl.GetItemState(i, LVIS_SELECTED)){
			// 선택된 메뉴의 재고가 없으면 메시지박스 출력
			for (int j = 0; j < set->stock->count; j++) {
				if (menulistctrl.GetItemText(i, 0) == set->stock->menu[j]->name) {
					if (set->stock->menu[j]->number == 0) {
						AfxMessageBox(L"재고가 부족합니다.");
						s_count = 1;
						break;
					}
				}
			}
			// 재고가 있으면 주문 목록에 추가
			if (s_count == 0) {
				CString str;
				str = menulistctrl.GetItemText(i, 0);
				set->AddMenu(str);
				ptest3Dlg->UpdateList();
				break;
			}
		}
	}
	*pResult = 0;
}