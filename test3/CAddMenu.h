#pragma once


// CAddMenu 대화 상자
class Setting;
class Ctest3Dlg;
class CAddMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CAddMenu)

public:
	CAddMenu(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAddMenu();
	Setting *set;
	Ctest3Dlg *ptest3Dlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combobox;    // 커피, 음료, 베이커리 선택 ㅋ
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();   // 취소 버튼
	afx_msg void OnBnClickedButton1();   // 추가 버튼
};
