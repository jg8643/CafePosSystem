// CCal.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CCal.h"
#include "afxdialogex.h"
#include "CCash.h"
#include "CCard.h"
// CCal 대화 상자

IMPLEMENT_DYNAMIC(CCal, CDialogEx)

CCal::CCal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CCal::~CCal()
{
}

void CCal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCal, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCal::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CCal::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CCal::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCal 메시지 처리기


BOOL CCal::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	CFont font;

	LOGFONT        LogFont;
	// Edit 컨트롤의 Font 정보를 LogFont에 가져옵니다.
	GetDlgItem(IDC_STATIC)->GetFont()->GetLogFont(&LogFont);
	// Font 글자 설정
	//LogFont.lfWeight = 1000;      // 굵기설정( MAX : 1000 )
	LogFont.lfHeight = 20;      // Font Size 설정
	// LogFont의정보로설정
	font.CreateFontIndirect(&LogFont);
	// EDit 박스의 폰트를 설정합니다.  
	GetDlgItem(IDC_STATIC)->SetFont(&font);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CCal::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCash ccash;
	CDialogEx::OnOK();
	ccash.DoModal();
	ccash.DestroyWindow();
}


void CCal::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CCal::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCard ccard;
	CDialogEx::OnOK();
	ccard.DoModal();
	ccard.DestroyWindow();
}
