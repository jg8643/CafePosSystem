#pragma once

// CTab1 대화 상자
class Setting;
class Ctest3Dlg;

class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl menulistctrl;    // 탭 메뉴
	CImageList imglist;        // 이미지 리스트
	Setting *set;
	Ctest3Dlg *ptest3Dlg;

	virtual BOOL OnInitDialog();
	void MenuSetting();     // coffee_count 의 개수만큼 이미지 리스트 생성
	void Add();  // 커피 탭에 메뉴버튼 셋팅
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);   // 메뉴 더블클릭
};
