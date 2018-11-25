// CReceipt.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CReceipt.h"
#include "afxdialogex.h"
#include "test3Dlg.h"
// CReceipt 대화 상자

IMPLEMENT_DYNAMIC(CReceipt, CDialogEx)

CReceipt::CReceipt(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{
	ptest3Dlg =(Ctest3Dlg *)::AfxGetMainWnd();
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
END_MESSAGE_MAP()


// CReceipt 메시지 처리기


void CReceipt::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ptest3Dlg->m_listctrl.DeleteAllItems();
	CDialogEx::OnCancel();
}
