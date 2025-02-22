#pragma once


// CMenuReceipt 대화 상자
class Setting;
class Ctest3Dlg;
class CMenuReceipt : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuReceipt)

public:
	CMenuReceipt(int skip ,CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMenuReceipt();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();

	int skip; // 영수증이 메뉴포함인지, 총액만 인지 확인용
	int list_count;
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
	afx_msg void OnDestroy();
};
