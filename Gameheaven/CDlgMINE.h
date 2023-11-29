#pragma once
#include "afxwin.h"

#include "afxdialogex.h"
#define IDC_BUTTON_GRID_00 1000 
#define IDC_BUTTON_GRID_01 1001
#define IDC_BUTTON_GRID_02 1002
#define IDC_BUTTON_GRID_03 1003
#define IDC_BUTTON_GRID_04 1004

#define IDC_BUTTON_GRID_10 1005
#define IDC_BUTTON_GRID_11 1006
#define IDC_BUTTON_GRID_12 1007
#define IDC_BUTTON_GRID_13 1008
#define IDC_BUTTON_GRID_14 1009

#define IDC_BUTTON_GRID_20 1010
#define IDC_BUTTON_GRID_21 1011
#define IDC_BUTTON_GRID_22 1012
#define IDC_BUTTON_GRID_23 1013
#define IDC_BUTTON_GRID_24 1014

#define IDC_BUTTON_GRID_30 1015
#define IDC_BUTTON_GRID_31 1016
#define IDC_BUTTON_GRID_32 1017
#define IDC_BUTTON_GRID_33 1018
#define IDC_BUTTON_GRID_34 1019

#define IDC_BUTTON_GRID_40 1020
#define IDC_BUTTON_GRID_41 1021
#define IDC_BUTTON_GRID_42 1022
#define IDC_BUTTON_GRID_43 1023
#define IDC_BUTTON_GRID_44 1024

#define IDC_ELAPSED_TIME_LABEL 2000


class CDlgMINE : public CDialogEx
{
public:
    CDlgMINE(CWnd* pParent = nullptr);

    void DoDataExchange(CDataExchange* pDX);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MINESWEEPER_DIALOG };
#endif

protected:
    HICON m_hIcon;
    CButton m_btnGrid[5][5]; // 버튼 배열
    BOOL isMine[5][5]; // 각 버튼에 지뢰가 있는지 여부를 나타내는 배열

    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnBnClickedButtonGrid();

    DECLARE_MESSAGE_MAP()

        void CreateButtons();
public:
    int row;
    int col;
    int CountAdjacentMines(int row, int col);

    void CheckGameWin();
    void StartGame();

private:
    CStatic m_elapsedTimeLabel; // 경과 시간을 나타낼 Static Text 컨트롤
    int m_elapsedSeconds;
    int m_elapsedTime = 0;
    static const UINT_PTR ID_TIMER_CLOCK = 2001;

    void GameWin();
    void GameOver();
    void RestartGame();
    void UpdateElapsedTime();
};