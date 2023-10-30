#pragma once
#include "afxdialogex.h"



// CDlgNonogram 대화 상자

class CDlgNonogram : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNonogram)

public:
	CDlgNonogram(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgNonogram();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NONOGRAM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedMfcbutton1();
	CMFCButton m_btn_1;
	bool m_bButton1;
};
