// CAddMenu.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CAddMenu.h"
#include "afxdialogex.h"
#include "order.h"
#include "Setting.h"
#include "Stock.h"
#include "test3Dlg.h"
#include "Cinventory.h"
// CAddMenu 대화 상자

IMPLEMENT_DYNAMIC(CAddMenu, CDialogEx)

CAddMenu::CAddMenu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
}

CAddMenu::~CAddMenu()
{
}

void CAddMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combobox);
}


BEGIN_MESSAGE_MAP(CAddMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddMenu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddMenu::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddMenu 메시지 처리기


BOOL CAddMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_combobox.AddString(L"커피");
	m_combobox.AddString(L"음료");
	m_combobox.AddString(L"베이커리");
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CAddMenu::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

// 메뉴 추가
void CAddMenu::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit *pEdit1, *pEdit2, *pEdit3;
	CString str[4];
	pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);

	m_combobox.GetLBText(m_combobox.GetCurSel(), str[0]);
	pEdit1->GetWindowText(str[1]);
	pEdit2->GetWindowText(str[2]);
	pEdit3->GetWindowText(str[3]);

	set->stock->AddMenu(str);
	((Cinventory *)GetParent())->UpdateList();

	CDialogEx::OnOK();
}
