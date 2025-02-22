#pragma once

// CTab3 대화 상자
class Setting;
class Ctest3Dlg;

class CTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab3)

public:
	CTab3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl menulistctrl;
	CImageList imglist;
	Setting *set;
	Ctest3Dlg *ptest3Dlg;

	virtual BOOL OnInitDialog();
	void MenuSetting();
	void Add();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
