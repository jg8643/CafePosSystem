// CTab3.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CTab3.h"
#include "afxdialogex.h"
#include "test3Dlg.h"
#include "order.h"
#include "Setting.h"
#include "Stock.h"
// CTab3 대화 상자

IMPLEMENT_DYNAMIC(CTab3, CDialogEx)

CTab3::CTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
}

CTab3::~CTab3()
{
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, menulistctrl);
}


BEGIN_MESSAGE_MAP(CTab3, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CTab3::OnNMDblclkList1)
END_MESSAGE_MAP()


// CTab3 메시지 처리기

// bread_count 만큼 이미지 리스트 셋팅
void CTab3::MenuSetting() {
	CBitmap bmp;
	int count = 0;
	bmp.LoadBitmap(IDB_BITMAP3);

	imglist.Create(72, 72, ILC_COLOR32, set->stock->bread_count, 0);

	Add();
}

// 베이커리 탭에 메뉴 버튼 생성
void CTab3::Add() {
	CBitmap bmp;
	int count = 0;
	bmp.LoadBitmap(IDB_BITMAP3);

	imglist.Add(&bmp, RGB(0, 0, 0));
	menulistctrl.SetImageList(&imglist, LVSIL_NORMAL);

	menulistctrl.DeleteAllItems();
	for (int i = 0; i < set->stock->count; i++) {
		if (set->stock->menu[i]->tab == L"베이커리") {
			menulistctrl.InsertItem(count++, set->stock->menu[i]->name);
		}
	}
}
BOOL CTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	MenuSetting();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTab3::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int s_count = 0;
	for (int i = 0; i < menulistctrl.GetItemCount(); i++){
		// 선택된 메뉴의 재고가 없으면 메시지박스 출력
		if (menulistctrl.GetItemState(i, LVIS_SELECTED)){
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
