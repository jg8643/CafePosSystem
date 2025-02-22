
// test3Dlg.h: 헤더 파일
//

#pragma once
class CTab1;
class CTab2;
class CTab3;
class Order;
class Setting;
// Ctest3Dlg 대화 상자
class Ctest3Dlg : public CDialogEx
{
// 생성입니다.
public:
	Ctest3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();  // 매출관리 다이얼로그 생성 (CSales)
	afx_msg void OnBnClickedButton4();  // 재고관리 다이얼로그 생성 (Cinventory)
	afx_msg void OnBnClickedButton5();  // 계산 다이얼로그 생성 (CCal)
	afx_msg void OnBnClickedButton3();  // 주문메뉴 삭제 버튼
	
	int mark;
	CTabCtrl m_tab;
	CTab1 *pDlg1;
	CTab2 *pDlg2;
	CTab3 *pDlg3;
	Setting *set;
	CListCtrl m_listctrl;
	CEdit pEdit;
	CEdit *cash_pEdit;

	CEdit* GetSumPriceBox();  // 합계 IDC_EDIT1 반환
	void UpdateStock();  // 재고가 5개 이하로 남은 품목 표시
	void UpdateList();   // 주문목록 리스트 컨트롤 업데이트
	void UpdateSum();    // 자동 합계
	void InitSum();      // 결제 후 합계 IDC_EDIT1 0으로 초기화
	void DeleteMenu();   // 주문목록 리스트 선택된 메뉴 삭제
};
