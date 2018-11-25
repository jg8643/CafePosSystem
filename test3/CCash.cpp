// CCash.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CCash.h"
#include "afxdialogex.h"
#include "CReceipt.h"
#include "test3Dlg.h"
#include "Setting.h"
#include "Stock.h"
#include "Sales.h"
// CCash 대화 상자

IMPLEMENT_DYNAMIC(CCash, CDialogEx)

CCash::CCash(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
}

CCash::~CCash()
{
}

void CCash::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCash, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CCash::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CCash::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCash 메시지 처리기


void CCash::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CCash::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit *pEdit1, *pEdit2;
	CString str1, str2;
	pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);
	pEdit2 = (CEdit *)GetDlgItem(IDC_EDIT2);
	pEdit1->GetWindowText(str1);
	pEdit2->GetWindowText(str2);
	if (str1 <= str2) {
		

		set->stock->ChangeStock();
		set->sales->ChangeSales();
		CReceipt creceipt;
		CDialogEx::OnOK();
		creceipt.DoModal();
		creceipt.DestroyWindow();
	}
	else {
		AfxMessageBox(L"돈모자라요");
	}
}


BOOL CCash::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	CEdit *pEdit;
	pEdit = (CEdit *)GetDlgItem(IDC_EDIT1);
	Ctest3Dlg *pctest3 = (Ctest3Dlg*)::AfxGetMainWnd();
	int sum = pctest3->set->GetSum();

	CString str;

	str.Format(L"%d", sum);

	pEdit->SetWindowText(str);
	
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}