#pragma once


// CCard 대화 상자

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
};
