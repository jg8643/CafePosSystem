#pragma once

// 매출관리

// CSales 대화 상자
class Setting;
class Ctest3Dlg;
class Sales;
class CSales : public CDialogEx
{
	DECLARE_DYNAMIC(CSales)

public:
	CSales(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSales();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int count;
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
	COleDateTime m_timeTP1;
	virtual BOOL OnInitDialog();
	COleDateTime m_timeTP2;
	CListCtrl m_listctrl2;
	afx_msg void OnBnClickedButton1();
	CDateTimeCtrl time1;
	CDateTimeCtrl time2;

	void AutoSum();
};
