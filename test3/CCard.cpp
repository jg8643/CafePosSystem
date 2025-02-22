// CCard.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CCard.h"
#include "afxdialogex.h"
#include "CReceipt.h"
#include "test3Dlg.h"
#include "Setting.h"
#include "Stock.h"
#include "Sales.h"

// CCard 대화 상자

IMPLEMENT_DYNAMIC(CCard, CDialogEx)

CCard::CCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG10, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
}

CCard::~CCard()
{
}

void CCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCard, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CCard::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CCard::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCard 메시지 처리기

// 주문 금액 표시
BOOL CCard::OnInitDialog()
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
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CCard::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit *pEdit1;
	CString str1;
	pEdit1 = (CEdit *)GetDlgItem(IDC_EDIT1);
	pEdit1->GetWindowText(str1);

	set->stock->WriteStockFile();  // 재고 파일 수정
	set->sales->ChangeSales();     // 매출 파일 수정
	ptest3Dlg->UpdateStock();      // 재고개수 5개 이하 부분 업데이트
	
	CReceipt creceipt;
	CDialogEx::OnOK();
	creceipt.DoModal();
	creceipt.DestroyWindow();
}

// 취소 버튼
void CCard::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}
