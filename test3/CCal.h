#pragma once

// 현금 or 카드

// CCal 대화 상자

class CCal : public CDialogEx
{
	DECLARE_DYNAMIC(CCal)

public:
	CCal(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCal();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
};
