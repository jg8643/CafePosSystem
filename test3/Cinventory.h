#pragma once

// 재고관리
class Setting;
class Ctest3Dlg;
class Order;
// Cinventory 대화 상자

class Cinventory : public CDialogEx
{
	DECLARE_DYNAMIC(Cinventory)

public:
	Cinventory(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cinventory();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrl3;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton5();    // 메뉴 추가 버튼
	afx_msg void OnBnClickedButton4();    // Save 버튼 : 재고 개수 수정하고 업데이트
	afx_msg void OnBnClickedOk();         // 확인 버튼
	afx_msg void OnBnClickedButton1();    // 메뉴 삭제 버튼

	Setting *set;
	Ctest3Dlg *ptest3Dlg;
	void UpdateList();   // 재고 목록 업데이트

};
