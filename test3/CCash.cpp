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
	DDX_Control(pDX, IDC_EDIT2, pEdit2);
}


BEGIN_MESSAGE_MAP(CCash, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CCash::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CCash::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCash 메시지 처리기

// 취소 버튼
void CCash::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

// 결제 버튼
void CCash::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit *pEdit1, *pEdit2;
	CString str1, str2;
	pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);
	pEdit2 = (CEdit *)GetDlgItem(IDC_EDIT2);
	pEdit1->GetWindowText(str1);
	pEdit2->GetWindowText(str2);

	// 주문 금액과 받은 돈 계산
	if (_ttoi(str1) <= _ttoi(str2)) {
		set->stock->WriteStockFile();   // 재고파일 수정
		set->sales->ChangeSales();      // 매출파일 수정
		ptest3Dlg->UpdateStock();       // 재고개수 5개 이하 부분 업데이트
		CReceipt creceipt;
		CDialogEx::OnOK();
		creceipt.DoModal();
		creceipt.DestroyWindow();
	}
	else {
		AfxMessageBox(L"금액이 부족합니다.");
	}
}

// 주문 금액 표시
BOOL CCash::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	pEdit2.SetFocus();

	// 받은 금액을 영수증에 넘겨주기 위해
	ptest3Dlg->cash_pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);

	CEdit *pEdit;
	pEdit = (CEdit *)GetDlgItem(IDC_EDIT1);
	Ctest3Dlg *pctest3 = (Ctest3Dlg*)::AfxGetMainWnd();
	int sum = pctest3->set->GetSum();

	CString str;

	str.Format(L"%d", sum);

	pEdit->SetWindowText(str);
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}