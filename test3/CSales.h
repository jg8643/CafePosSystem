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
	int count;                  // 매출 관리 리스트컨트롤 목록 개수
	CListCtrl m_listctrl2;      // 매출 관리 리스트컨트롤
	CDateTimeCtrl time1;        // 선택한 날짜 1
	CDateTimeCtrl time2;        // 선택한 날짜 2
	Setting *set;
	Ctest3Dlg *ptest3Dlg;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();   // 검색 버튼
	void AutoSum();                      // 자동 합계
};
