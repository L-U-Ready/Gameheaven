// CDlgMain.cpp: 구현 파일
//

#include "pch.h"
#include "Gameheaven.h"
#include "afxdialogex.h"
#include "CDlgMain.h"
#include "CDlgNonogram.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "GameheavenDoc.h"


// CDlgMain 대화 상자

IMPLEMENT_DYNAMIC(CDlgMain, CDialogEx)

CDlgMain::CDlgMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MENU, pParent)
{

}

CDlgMain::~CDlgMain()
{
}

void CDlgMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMain, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_NONOGRAM, &CDlgMain::OnBnClickedButtonNonogram)
	ON_BN_CLICKED(IDC_BUTTON_MINE, &CDlgMain::OnBnClickedButtonMine)
	ON_BN_CLICKED(IDC_BUTTON_SUDOKU, &CDlgMain::OnBnClickedButtonSudoku)
	ON_BN_CLICKED(IDC_BUTTON_POKEMON, &CDlgMain::OnBnClickedButtonPokemon)
END_MESSAGE_MAP()


// CDlgMain 메시지 처리기


void CDlgMain::OnBnClickedButtonNonogram()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDlgNonogram* pNonogram = new CDlgNonogram;

	if (pNonogram->DoModal() == IDOK)		// DoModal()함수는 대화상자를 실행시킨다.
	{
		// 인스턴스 얻기
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CChildFrame* pChild = (CChildFrame*)pFrame->GetActiveFrame();
		CGameheavenDoc* pDoc = (CGameheavenDoc*)pChild->GetActiveDocument();

		UpdateData(TRUE);				// 데이터를 변수에 저장
		Invalidate();				// 화면 갱신	
	}
}


void CDlgMain::OnBnClickedButtonMine()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDlgMain::OnBnClickedButtonSudoku()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CDlgMain::OnBnClickedButtonPokemon()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
