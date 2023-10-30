#pragma once
#include "afxdialogex.h"


// CDlgMain 대화 상자

class CDlgMain : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMain)

public:
	CDlgMain(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgMain();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNonogram();
	afx_msg void OnBnClickedButtonMine();
	afx_msg void OnBnClickedButtonSudoku();
	afx_msg void OnBnClickedButtonPokemon();
};
