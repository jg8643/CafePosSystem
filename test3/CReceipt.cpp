// CReceipt.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CReceipt.h"
#include "afxdialogex.h"
#include "test3Dlg.h"
#include "Setting.h"
#include "CMenuReceipt.h"
// CReceipt 대화 상자

IMPLEMENT_DYNAMIC(CReceipt, CDialogEx)

CReceipt::CReceipt(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{
	ptest3Dlg =(Ctest3Dlg *)::AfxGetMainWnd();
	set = ptest3Dlg->set;
}

CReceipt::~CReceipt()
{
}

void CReceipt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CReceipt, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CReceipt::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CReceipt::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CReceipt::OnBnClickedButton2)
END_MESSAGE_MAP()


// CReceipt 메시지 처리기


void CReceipt::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ptest3Dlg->m_listctrl.DeleteAllItems();
	set->count = 0;
	ptest3Dlg->InitSum();
	CDialogEx::OnOK();
}

// 메뉴 포함 영수증
void CReceipt::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMenuReceipt cmenureceipt(1);
	cmenureceipt.DoModal();
	cmenureceipt.DestroyWindow();

	CDialogEx::OnOK();

}

// 메뉴 X 금액만 영수증
void CReceipt::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMenuReceipt cmenureceipt(0);
	cmenureceipt.DoModal();
	cmenureceipt.DestroyWindow();
	CDialogEx::OnOK();
}
