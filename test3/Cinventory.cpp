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
	ON_BN_CLICKED(IDC_BUTTON1, &Cinventory::OnBnClickedButton1)
END_MESSAGE_MAP()


// Cinventory 메시지 처리기


BOOL Cinventory::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rt1;
	CEdit *pEdit1, *pEdit2;
	pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit1->SetWindowText(L"개수");
	pEdit2->SetWindowText(L"판매 가격");

	m_listctrl3.GetWindowRect(&rt1);
	m_listctrl3.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_listctrl3.InsertColumn(0, TEXT("이름"), LVCFMT_LEFT, rt1.Width()*0.5);
	m_listctrl3.InsertColumn(1, TEXT("개수"), LVCFMT_LEFT, rt1.Width()*0.2);
	m_listctrl3.InsertColumn(2, TEXT("판매 가격"), LVCFMT_LEFT, rt1.Width()*0.29);

	UpdateList();
	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



// 재고 목록 더블클릭
void Cinventory::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i < m_listctrl3.GetItemCount(); i++)
	{
		if (m_listctrl3.GetItemState(i, LVIS_SELECTED))
		{
			CString str1, str2;
			CEdit *pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
			CEdit *pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);

			str1 = m_listctrl3.GetItemText(i, 1);
			str2 = m_listctrl3.GetItemText(i, 2);
			pEdit1->SetWindowText(str1);
			pEdit2->SetWindowText(str2);

			// 선택된 목록의 인덱스 넣어주기
			set->stock->i_count = i; 
		}
	}
	*pResult = 0;
}

// 리스트 업데이트
void Cinventory::UpdateList() {
	m_listctrl3.DeleteAllItems();
	for (int i = 0; i < set->stock->count; i++) {
		m_listctrl3.InsertItem(i, set->stock->menu[i]->name);
		m_listctrl3.SetItem(i, 1, LVIF_TEXT, set->stock->menu[i]->GetNumber(), NULL, NULL, NULL, NULL);
		m_listctrl3.SetItem(i, 2, LVIF_TEXT, set->stock->menu[i]->GetPrice(), NULL, NULL, NULL, NULL);
	}
}

// Save 버튼 : 재고 개수 수정하고 업데이트
void Cinventory::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str1, str2;
	CEdit *pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit *pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	int i_count = set->stock->i_count;
	pEdit1->GetWindowText(str1);
	pEdit2->GetWindowText(str2);

	set->stock->menu[i_count]->number = _ttoi(str1);
	set->stock->menu[i_count]->price = _ttoi(str2);
	UpdateList();
	set->stock->WriteStockFile();
}

// 메뉴 추가버튼
void Cinventory::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드 를 추가합니다.
	CAddMenu caddmenu;
	caddmenu.DoModal();
	caddmenu.DestroyWindow();
}

// 메뉴 삭제 버튼
void Cinventory::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	set->stock->DeleteMenu(&m_listctrl3);
	UpdateList();
	set->stock->WriteStockFile();
}

// 확인 버튼 : 메뉴가 추가, 삭제 되었다면 탭 메뉴에 반영
void Cinventory::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ptest3Dlg->pDlg1->Add();
	ptest3Dlg->pDlg2->Add();
	ptest3Dlg->pDlg3->Add();
	ptest3Dlg->UpdateStock();
	CDialogEx::OnOK();
}