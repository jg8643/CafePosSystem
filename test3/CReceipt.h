#pragma once

// 영수증 관련

// CReceipt 대화 상자
class Ctest3Dlg;
class CReceipt : public CDialogEx
{
	DECLARE_DYNAMIC(CReceipt)

public:
	CReceipt(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CReceipt();
	Ctest3Dlg *ptest3Dlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
};
