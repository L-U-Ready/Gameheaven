// CDlgNonogram.cpp: 구현 파일
//

#include "pch.h"
#include "Gameheaven.h"
#include "afxdialogex.h"
#include "CDlgNonogram.h"


// CDlgNonogram 대화 상자

IMPLEMENT_DYNAMIC(CDlgNonogram, CDialogEx)

CDlgNonogram::CDlgNonogram(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NONOGRAM, pParent)
{
}

CDlgNonogram::~CDlgNonogram()
{
}

void CDlgNonogram::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON_1, m_btn_1);
}


BEGIN_MESSAGE_MAP(CDlgNonogram, CDialogEx)

	ON_BN_CLICKED(IDC_MFCBUTTON_1, &CDlgNonogram::OnBnClickedMfcbutton1)
END_MESSAGE_MAP()


// CDlgNonogram 메시지 처리기

BOOL CDlgNonogram::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_bButton1 = FALSE;
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CDlgNonogram::OnBnClickedMfcbutton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bButton1 == FALSE) {
		m_btn_1.SetFaceColor(RGB(255, 255, 255), true);
		m_bButton1 = TRUE;
	}
	else {
		m_btn_1.SetFaceColor(RGB(0, 0, 0), true);
		m_bButton1 = FALSE;
	}
}
