// CCard.cpp: 구현 파일
//

#include "stdafx.h"
#include "test3.h"
#include "CCard.h"
#include "afxdialogex.h"


// CCard 대화 상자

IMPLEMENT_DYNAMIC(CCard, CDialogEx)

CCard::CCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG10, pParent)
{

}

CCard::~CCard()
{
}

void CCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCard, CDialogEx)
END_MESSAGE_MAP()


// CCard 메시지 처리기
