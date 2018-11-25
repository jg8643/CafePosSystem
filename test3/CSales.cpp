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
	, m_timeTP1(COleDateTime::GetCurrentTime())
	, m_timeTP2(COleDateTime::GetCurrentTime())
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
	count = 0; // list 카운터
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
	m_listctrl2.InsertColumn(2, TEXT("판매금액"), LVCFMT_LEFT, rt1.Width()*0.3);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSales::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listctrl2.DeleteAllItems();   //지우고 다시쓰기
	count = 0;
	CTime temptime1, temptime2;

	CString str1, str2;
	DWORD dwResult1, dwResult2;
	int i = 0, temp;
	dwResult1 = time1.GetTime(temptime1);
	dwResult2 = time2.GetTime(temptime2);
	
	str1 = temptime1.Format(_T("%Y%m%d"));
	str2 = temptime2.Format(_T("%Y%m%d"));
	
	i = startpos(i, _ttoi(str1));
	temp = _ttoi(str2) + 1;
	while(set->sales->s_data[i]->date !=  temp ){
		m_listctrl2.InsertItem(count, set->sales->s_data[i]->name);
		m_listctrl2.SetItem(count, 1, LVIF_TEXT, set->sales->s_data[i]->GetNumber(), NULL, NULL, NULL, NULL);
		m_listctrl2.SetItem(count, 2, LVIF_TEXT, set->sales->s_data[i]->GetPrice(), NULL, NULL, NULL, NULL);
		count++;
		i++;
		if (&set->sales->s_data[i]->date == NULL)
			break;
	}
	

}

int CSales::startpos(int index, int str)
{
	int count = 0;
	for (int i = 0; i < set->sales->count; i++) {
		if (count == 1)
			break;
		if (set->sales->s_data[i]->date == str) {
			index = i;
			count = 1;
		}
		else
			index = 0;
	}
	return index;
}
