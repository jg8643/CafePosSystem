#pragma once

// 카드 결제

// CCard 대화 상자
class Setting;
class Ctest3Dlg;
class CCard : public CDialogEx
{
	DECLARE_DYNAMIC(CCard)

public:
	CCard(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCard();
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
