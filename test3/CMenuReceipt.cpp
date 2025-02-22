// CMenuReceipt.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CMenuReceipt.h"
#include "afxdialogex.h"
#include "test3Dlg.h"
#include "Setting.h"
#include <time.h>
// CMenuReceipt 대화 상자

IMPLEMENT_DYNAMIC(CMenuReceipt, CDialogEx)

CMenuReceipt::CMenuReceipt(int skip, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG11, pParent)
{
	this->skip = skip;
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
	list_count = ptest3Dlg->m_listctrl.GetItemCount();
}

CMenuReceipt::~CMenuReceipt()
{
}

void CMenuReceipt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMenuReceipt, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMenuReceipt 메시지 처리기


BOOL CMenuReceipt::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	// 메뉴 포함 영수증
	if (skip == 1) {
		MoveWindow(810, 250, 335, (list_count * 20) + 400);
	}
	else {
		MoveWindow(810, 250, 335, 290);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CMenuReceipt::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	GetClientRect(rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


HBRUSH CMenuReceipt::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CMenuReceipt::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	int i = 0;
	
	CString str1, str2, str3;
	ptest3Dlg->pEdit.GetWindowText(str1);
	if(ptest3Dlg->cash_pEdit != NULL)
		ptest3Dlg->cash_pEdit->GetWindowText(str2);
	CFont font, *pOldFont;
	font.CreatePointFont(150, _T("Lucida Grande Bold"));
	pOldFont = (CFont*)dc.SelectObject(&font);

	// 오늘 년 월 일 시간 가져오기
	CString C_time;
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d  %X", &tstruct);
	C_time = buf;


	dc.TextOut(125, 20, L"영수증");
	font.DeleteObject();
	font.CreatePointFont(100, _T("Lucida Grande Bold"));
	pOldFont = (CFont*)dc.SelectObject(&font);
	dc.TextOut(170, 50, C_time);
	dc.TextOut(10, 70, L"---------------------------------------");
	dc.TextOut(10, 90, L"상호 : 금오 카페 포스기");
	dc.TextOut(10, 110, L"사업자 : 이정규");
	dc.TextOut(10, 130, L"주소: 경상북도 구미시 대학로 61");
	dc.TextOut(10, 150, L"전화번호: 010-XXXX-XXXX");
	dc.TextOut(10, 170, L"---------------------------------------");
	dc.TextOut(10, 180, L"---------------------------------------");
	// 메뉴 포함 영수증
	if (skip == 1) {
		dc.TextOut(10, 200, L"상품                          수량         판매금액");
		dc.TextOut(10, 220, L"---------------------------------------");
		for (i; i < ptest3Dlg->m_listctrl.GetItemCount(); i++) {
			dc.TextOut(10, (i * 20) + 240, ptest3Dlg->m_listctrl.GetItemText(i, 0));
			dc.TextOut(175, (i * 20) + 240, ptest3Dlg->m_listctrl.GetItemText(i, 1));
			dc.TextOut(252, (i * 20) + 240, ptest3Dlg->m_listctrl.GetItemText(i, 2));
		}
		i = (i * 20) + 240;
		dc.TextOut(10, i + 40, L"---------------------------------------");
		dc.TextOut(10, i + 50, L"---------------------------------------");
		dc.TextOut(10, i + 70, L"받을금액 :");
		dc.TextOut(252, i + 70, str1);
		dc.TextOut(10, i + 90, L"---------------------------------------");
		dc.TextOut(10, i + 110, L"받은금액 :");
		if (str2 != L"") {
			// 현금 계산일 경우
			dc.TextOut(252, i + 110, str2);
			dc.TextOut(10, i + 130, L"거스름돈 :");
			int change = _ttoi(str2) - _ttoi(str1);
			str3.Format(L"%d", change);
			dc.TextOut(252, i + 130, str3);
			ptest3Dlg->cash_pEdit = NULL;
		}
		else {
			// 카드 계산일 경우
			dc.TextOutW(252, i + 110, str1);
			dc.TextOut(10, i + 130, L"거스름돈 :");
			dc.TextOut(252, i + 130, L"0");
		}
		i = i + 130;
	}
	// 메뉴 X 금액만 영수증
	else {
		dc.TextOut(10, 200, L"받을금액 :");
		dc.TextOut(252, 200, str1);
		dc.TextOut(10, 220, L"---------------------------------------");
		dc.TextOut(10, 240, L"받은금액 :");
		if (str2 != L"") {
			// 현금 계산일 경우
			dc.TextOut(252, 240, str2);
			dc.TextOut(10, 260, L"거스름돈 :");
			int change = _ttoi(str2) - _ttoi(str1);
			str3.Format(L"%d", change);
			dc.TextOut(252, 260, str3);
			ptest3Dlg->cash_pEdit = NULL;
		}
		else {
			// 카드 계산일 경우
			dc.TextOut(252, 240, str1);
			dc.TextOut(10, 260, L"거스름돈 :");
			dc.TextOut(252, 260, L"0");
		}
	}
	font.DeleteObject();
}


void CMenuReceipt::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	ptest3Dlg->m_listctrl.DeleteAllItems();
	set->count = 0;
	ptest3Dlg->InitSum();
}
