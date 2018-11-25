#pragma once

// 현금 결제

// CCash 대화 상자
class Setting;
class Ctest3Dlg;
class CCash : public CDialogEx
{
	DECLARE_DYNAMIC(CCash)

public:
	CCash(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCash();
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();
	virtual BOOL OnInitDialog();
	void ChangeStock();
};
