// CSales.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CSales.h"
#include "afxdialogex.h"


// CSales 대화 상자

IMPLEMENT_DYNAMIC(CSales, CDialogEx)

CSales::CSales(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_timeTP1(COleDateTime::GetCurrentTime())
	, m_timeTP2(COleDateTime::GetCurrentTime())
{

}

CSales::~CSales()
{
}

void CSales::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_timeTP1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_timeTP2);
	DDX_Control(pDX, IDC_LIST1, m_listctrl2);
}


BEGIN_MESSAGE_MAP(CSales, CDialogEx)
END_MESSAGE_MAP()


// CSales 메시지 처리기


BOOL CSales::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rt1;
	m_listctrl2.GetWindowRect(&rt1);
	m_listctrl2.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl2.InsertColumn(0, TEXT("이름"), LVCFMT_LEFT, rt1.Width()*0.5);
	m_listctrl2.InsertColumn(1, TEXT("판매량"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl2.InsertColumn(2, TEXT("판매금액"), LVCFMT_LEFT, rt1.Width()*0.3);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
