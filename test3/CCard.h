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
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();  // 결제 버튼
	afx_msg void OnBnClickedCancel();   // 취소 버튼
	virtual BOOL OnInitDialog();        // 주문 금액 표시

	Setting *set;
	Ctest3Dlg *ptest3Dlg;
};
