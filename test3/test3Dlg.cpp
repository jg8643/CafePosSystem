
// test3Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "test3Dlg.h"
#include "afxdialogex.h"
#include "CTab1.h"
#include "CTab2.h"
#include "CTab3.h"
#include "CSales.h"
#include "Cinventory.h"
#include "CCal.h"
#include "Setting.h"
#include "order.h"
#include "Stock.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest3Dlg 대화 상자
Ctest3Dlg::Ctest3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	mark = -1;
}

void Ctest3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, pEdit);
}

BEGIN_MESSAGE_MAP(Ctest3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Ctest3Dlg::OnLvnItemchangedList1)
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Ctest3Dlg::OnTcnSelchangeTab1)
ON_BN_CLICKED(IDC_BUTTON2, &Ctest3Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON4, &Ctest3Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &Ctest3Dlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON3, &Ctest3Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Ctest3Dlg 메시지 처리기

BOOL Ctest3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.
	

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.


	set = new Setting(this);  //재고, 매출용 set 생성


	// 주문 목록 리스트컨트롤 셋팅
	CRect rt1;
	m_listctrl.GetWindowRect(&rt1);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl.InsertColumn(0, TEXT("이름"), LVCFMT_LEFT, rt1.Width()*0.5);
	m_listctrl.InsertColumn(1, TEXT("개수"), LVCFMT_LEFT, rt1.Width()*0.19);
	m_listctrl.InsertColumn(2, TEXT("단가"), LVCFMT_LEFT, rt1.Width()*0.3);

	// 탭컨트롤 셋팅
	m_tab.InsertItem(0, _T("커피"));
	m_tab.InsertItem(1, _T("음료"));
	m_tab.InsertItem(2, _T("베이커리"));

	m_tab.SetCurSel(0);

	CRect rect;
	m_tab.GetWindowRect(&rect);
	
	pDlg1 = new CTab1;
	pDlg1->Create(IDD_DIALOG1, &m_tab);
	pDlg1->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg1->ShowWindow(SW_SHOW);

	pDlg2 = new CTab2;
	pDlg2->Create(IDD_DIALOG2, &m_tab);
	pDlg2->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg2->ShowWindow(SW_HIDE);

	pDlg3 = new CTab3;
	pDlg3->Create(IDD_DIALOG3, &m_tab);
	pDlg3->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg3->ShowWindow(SW_HIDE);
	
	UpdateStock();   // 재고가 5개 이하로 남은 품목 표시
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Ctest3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Ctest3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ctest3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest3Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	*pResult = 0;
}


// 탭메뉴 눌렀을 때
void Ctest3Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_tab.GetCurSel();

	switch (sel) {
	case 0:
		pDlg1->ShowWindow(SW_SHOW);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		break;

	case 1:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_SHOW);
		pDlg3->ShowWindow(SW_HIDE);
		break;
	case 2:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}


CEdit* Ctest3Dlg::GetSumPriceBox() {
	return (CEdit*)GetDlgItem(IDC_EDIT1);
}

// 매출관리 다이얼로그 생성 (CSales)
void Ctest3Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSales csales;
	csales.DoModal();
	csales.DestroyWindow();
}

// 재고관리 다이얼로그 생성 (Cinventory)
void Ctest3Dlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Cinventory cinventory;
	cinventory.DoModal();
	cinventory.DestroyWindow();
}

// 계산 다이얼로그 생성 (CCal)
void Ctest3Dlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCal ccal;
	ccal.DoModal();
	ccal.DestroyWindow();
}

// 주문목록 리스트중 선택 메뉴 삭제
void Ctest3Dlg::DeleteMenu() {
	mark = m_listctrl.GetSelectionMark();
	if (mark >= 0) {
		// 선택된 메뉴를 삭제시 재고파일의 개수 수정
		for (int j = 0; j < set->stock->count; j++) {
			if (m_listctrl.GetItemText(mark, 0) == set->stock->menu[j]->name) {
				set->stock->menu[j]->number += _ttoi(m_listctrl.GetItemText(mark, 1));
			}
		}

		// 전체 삭제 후 끌어올리기
		m_listctrl.DeleteItem(mark);   
		set->count = set->count - 1;
		for (int i = mark; i < set->count; i++) {
			set->order[i] = set->order[i + 1];
		}
	}
	else
		AfxMessageBox(L"취소할 메뉴를 선택해주세요.");
	UpdateSum();
}

// 삭제 버튼
void Ctest3Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DeleteMenu();
}

// 재고가 5개 이하로 남은 품목 표시
void Ctest3Dlg::UpdateStock()
{
	CEdit* pedit = (CEdit*)GetDlgItem(IDC_EDIT2);
	CString str = L"";
	for (int i = 0; i < set->stock->count; i++) {
		if (set->stock->menu[i]->number <= 5) {
			str += set->stock->menu[i]->name + " " + set->stock->menu[i]->GetNumber() + L"개   ";
		}
	}
	if(str != L"")
		str += L"남았습니다.";
	pedit->SetWindowText(str);
}

// 주문목록 리스트 컨트롤 업데이트
void Ctest3Dlg::UpdateList() {
	m_listctrl.DeleteAllItems();

	for (int i = 0; i < set->count; i++) {
		m_listctrl.InsertItem(i, set->order[i]->name);
		m_listctrl.SetItem(i, 1, LVIF_TEXT, set->order[i]->GetNumber(), NULL, NULL, NULL, NULL);
		m_listctrl.SetItem(i, 2, LVIF_TEXT, set->order[i]->GetTotalPrice(), NULL, NULL, NULL, NULL);
	}

	UpdateSum();
}

// 자동 합계
void Ctest3Dlg::UpdateSum() {
	CString sumprice;
	sumprice.Format(L"%d", set->GetSum());
	GetSumPriceBox()->SetWindowText(sumprice);
}

// 합계 0으로 초기화
void Ctest3Dlg::InitSum() {
	
	GetSumPriceBox()->SetWindowText(L"0");
}