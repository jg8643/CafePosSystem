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
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
	void UpdateList();
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
	afx_msg void OnBnClickedButton5();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	void DeleteMenu();
	void OnBnClickedButton1();

};
