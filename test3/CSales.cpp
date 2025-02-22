// CSales.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CSales.h"
#include "afxdialogex.h"
#include "Sales.h"
#include "Setting.h"
#include "test3Dlg.h"
#include "Stock.h"
// CSales 대화 상자

IMPLEMENT_DYNAMIC(CSales, CDialogEx)

CSales::CSales(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
	count = 0;
}

CSales::~CSales()
{
}

void CSales::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl2);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, time1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, time2);
}


BEGIN_MESSAGE_MAP(CSales, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSales::OnBnClickedButton1)
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
	m_listctrl2.InsertColumn(2, TEXT("판매금액"), LVCFMT_LEFT, rt1.Width()*0.29);


	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSales::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listctrl2.DeleteAllItems();   //지우고 다시쓰기
	
	set->sales->InitTdata(); // t_date 초기화

	// 선택된 날짜 str1, str2에 넣기
	CTime temptime1, temptime2;
	CString str1, str2;
	DWORD dwResult1, dwResult2;
	dwResult1 = time1.GetTime(temptime1);
	dwResult2 = time2.GetTime(temptime2);
	str1 = temptime1.Format(_T("%Y%m%d"));
	str2 = temptime2.Format(_T("%Y%m%d"));
	
	// 선택된 기간 동안 판매된 t_data 생성
	set->sales->SetTdata(str1, str2);

	// 리스트 컨트롤 채우기
	for (int j = 0; j < set->sales->t_count; j++) {
		m_listctrl2.InsertItem(j, set->sales->t_data[j]->name);
		m_listctrl2.SetItem(j, 1, LVIF_TEXT, set->sales->t_data[j]->GetNumber(), NULL, NULL, NULL, NULL);
		m_listctrl2.SetItem(j, 2, LVIF_TEXT, set->sales->t_data[j]->GetPrice(), NULL, NULL, NULL, NULL);
	}

	AutoSum();
}

// 자동 합계
void CSales::AutoSum()
{
	CString str;
	CEdit * pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	int temp = 0;
	for (int i = 0; i < m_listctrl2.GetItemCount(); i++) {
		temp += _ttoi(m_listctrl2.GetItemText(i, 2));
	}
	str.Format(L"%d", temp);
	pEdit->SetWindowText(str);
}
