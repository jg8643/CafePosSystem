// Cinventory.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "Cinventory.h"
#include "afxdialogex.h"
#include "CAddMenu.h"
#include "Setting.h"
#include "Stock.h"
#include "test3Dlg.h"
#include "CTab1.h"
#include "CTab2.h"
#include "CTab3.h"
// Cinventory 대화 상자

IMPLEMENT_DYNAMIC(Cinventory, CDialogEx)

Cinventory::Cinventory(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{
	ptest3Dlg = (Ctest3Dlg*)::AfxGetMainWnd();
	set = ptest3Dlg->set;
	
}

Cinventory::~Cinventory()
{
}

void Cinventory::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl3);
}


BEGIN_MESSAGE_MAP(Cinventory, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &Cinventory::OnBnClickedButton5)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &Cinventory::OnNMDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON4, &Cinventory::OnBnClickedButton4)
	ON_BN_CLICKED(IDOK, &Cinventory::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &Cinventory::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &Cinventory::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Cinventory::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cinventory 메시지 처리기


BOOL Cinventory::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rt1;
	m_listctrl3.GetWindowRect(&rt1);
	m_listctrl3.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl3.InsertColumn(0, TEXT("이름"), LVCFMT_LEFT, rt1.Width()*0.7);
	m_listctrl3.InsertColumn(1, TEXT("개수"), LVCFMT_LEFT, rt1.Width()*0.3);

	for (int i = 0; i < set->stock->count; i++) {
		m_listctrl3.InsertItem(i, set->stock->menu[i]->name);
		m_listctrl3.SetItem(i, 1, LVIF_TEXT, set->stock->menu[i]->GetNumber(), NULL, NULL, NULL, NULL);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}




void Cinventory::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i < m_listctrl3.GetItemCount(); i++)
	{
		if (m_listctrl3.GetItemState(i, LVIS_SELECTED))
		{
			CString str;
			CEdit *pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
			str = m_listctrl3.GetItemText(i, 1);
			pEdit->SetWindowText(str);
			set->stock->i_count = i; 
		}
	}
	*pResult = 0;
}
void Cinventory::UpdateList() {
	m_listctrl3.DeleteAllItems();
	for (int i = 0; i < set->stock->count; i++) {
		m_listctrl3.InsertItem(i, set->stock->menu[i]->name);
		m_listctrl3.SetItem(i, 1, LVIF_TEXT, set->stock->menu[i]->GetNumber(), NULL, NULL, NULL, NULL);
	}
}

void Cinventory::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	CEdit *pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	int i_count = set->stock->i_count;
	pEdit->GetWindowText(str);
	set->stock->menu[i_count]->number = _ttoi(str);
	UpdateList();
	set->stock->WriteStockFile();
}
void Cinventory::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드 를 추가합니다.
	CAddMenu caddmenu;
	caddmenu.DoModal();
	caddmenu.DestroyWindow();
}


void Cinventory::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ptest3Dlg->pDlg1->Add();
	ptest3Dlg->pDlg2->Add();
	ptest3Dlg->pDlg3->Add();
	CDialogEx::OnOK();
}

// -버튼
void Cinventory::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit * pEdit;
	CString str;
	int temp;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->GetWindowText(str);
	temp = _ttoi(str);
	temp--;
	str.Format(_T("%d"), temp);

	pEdit->SetWindowText(str);

}

// +버튼
void Cinventory::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit * pEdit;
	CString str;
	int temp;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->GetWindowText(str);
	temp = _ttoi(str);
	temp++;
	str.Format(_T("%d"), temp);
	pEdit->SetWindowText(str);
}

void Cinventory::DeleteMenu() {
	int mark = m_listctrl3.GetSelectionMark();

	if (mark >= 0) {
		for (int i = 0; i < set->stock->count; i++) {
			if (m_listctrl3.GetItemText(mark, 0) == set->stock->menu[i]->name) {
				if (set->stock->menu[i]->tab == L"커피")
					set->stock->coffee_count--;
				else if (set->stock->menu[i]->tab == L"음료")
					set->stock->juice_count--;
				else
					set->stock->bread_count--;

				for (int j = i; j < set->stock->count; j++) {
					set->stock->menu[j] = set->stock->menu[j + 1];
				}
				set->stock->count = set->stock->count - 1;
			}
			
		}
		m_listctrl3.DeleteItem(mark);
		UpdateList();
		set->stock->WriteStockFile();
	}
	else
		AfxMessageBox(L"취소할 메뉴를 선택해주세요.");
}
void Cinventory::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DeleteMenu();
	
}
