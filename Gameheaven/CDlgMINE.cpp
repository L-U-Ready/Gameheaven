
#include "pch.h"
#include "Gameheaven.h"
#include "afxdialogex.h"
#include "CDlgMINE.h"

#define NUM_MINES 5 // 지뢰 개수


CDlgMINE::CDlgMINE(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MINESWEEPER_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgMINE::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgMINE, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()

    ON_WM_TIMER()


    ON_BN_CLICKED(IDC_BUTTON_GRID_00, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_01, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_02, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_03, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_04, &CDlgMINE::OnBnClickedButtonGrid)

    ON_BN_CLICKED(IDC_BUTTON_GRID_10, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_11, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_12, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_13, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_14, &CDlgMINE::OnBnClickedButtonGrid)

    ON_BN_CLICKED(IDC_BUTTON_GRID_20, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_21, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_22, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_23, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_24, &CDlgMINE::OnBnClickedButtonGrid)

    ON_BN_CLICKED(IDC_BUTTON_GRID_30, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_31, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_32, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_33, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_34, &CDlgMINE::OnBnClickedButtonGrid)

    ON_BN_CLICKED(IDC_BUTTON_GRID_40, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_41, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_42, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_43, &CDlgMINE::OnBnClickedButtonGrid)
    ON_BN_CLICKED(IDC_BUTTON_GRID_44, &CDlgMINE::OnBnClickedButtonGrid)

END_MESSAGE_MAP()

BOOL CDlgMINE::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    // 경과 시간 표시를 위한 Static Text 컨트롤 생성
    m_elapsedTimeLabel.Create(_T("00:00"), WS_VISIBLE | WS_CHILD, CRect(125, 300, 180, 400), this, IDC_ELAPSED_TIME_LABEL);

    int result = MessageBox(_T("게임을 시작하시겠습니까?"), _T("게임 시작"), MB_YESNO | MB_ICONQUESTION);
    if (result == IDYES) {
        StartGame(); // 게임 시작 함수 호출 (타이머 시작 등)
    }
    else {
        EndDialog(0); // 다이얼로그 종료
    }

    return TRUE;
}

void CDlgMINE::OnPaint()
{
    CPaintDC dc(this);
    // 그리기 코드를 추가합니다.
}

HCURSOR CDlgMINE::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CDlgMINE::StartGame() {
    // 버튼 생성 및 지뢰 배치
    CreateButtons();

    // 타이머 시작
    SetTimer(ID_TIMER_CLOCK, 1000, nullptr);

    m_elapsedSeconds = 0; // 경과 시간 초기화
}

// OnTimer 함수를 구현하여 경과 시간을 업데이트합니다.
void CDlgMINE::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == ID_TIMER_CLOCK)
    {
        UpdateElapsedTime();
    }

    CDialogEx::OnTimer(nIDEvent);
}

void CDlgMINE::UpdateElapsedTime() {


    // 분과 초를 계산합니다.
    int minutes = m_elapsedSeconds / 60;
    int seconds = m_elapsedSeconds % 60;

    // 시간을 형식에 맞게 변환하여 Static Text 컨트롤에 표시합니다.
    CString timeStr;
    timeStr.Format(_T("%02d:%02d"), minutes, seconds);
    m_elapsedTimeLabel.SetWindowText(timeStr);

    m_elapsedSeconds++; // 경과 시간을 1초씩 증가 // 해당 함수 맨 위에 있으면 1초를 더하고 시작해서 재시작 했을 때 1부터 시작하기에 맨 밑으로 내렸음
    m_elapsedTime = m_elapsedSeconds;
}

void CDlgMINE::CreateButtons()
{
    CRect rectButton;
    int buttonWidth = 50;
    int buttonHeight = 50;
    int startX = 20;
    int startY = 20;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            rectButton.SetRect(startX + j * buttonWidth, startY + i * buttonHeight,
                startX + (j + 1) * buttonWidth, startY + (i + 1) * buttonHeight);
            m_btnGrid[i][j].Create(_T(""), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, rectButton, this, IDC_BUTTON_GRID_00 + i * 5 + j);

        }
    }

    // 지뢰 배치
    srand(static_cast<unsigned int>(time(nullptr)));

    int minesPlaced = 0;
    while (minesPlaced < NUM_MINES) {
        int randomRow = rand() % 5;
        int randomCol = rand() % 5;

        if (!isMine[randomRow][randomCol]) {
            isMine[randomRow][randomCol] = TRUE;
            minesPlaced++;
        }
    }
}


int CDlgMINE::CountAdjacentMines(int row, int col) { //주변 지뢰 개수 count
    int count = 0;

    // 주변의 8개 방향을 확인하기 위한 루프
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;

            // 인덱스가 그리드 범위를 벗어나는지 확인
            if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 5) {
                // 현재 버튼 주변의 지뢰가 있는지 확인하고 카운트
                if (isMine[newRow][newCol]) {
                    count++;
                }
            }
        }
    }

    return count;
}

void CDlgMINE::OnBnClickedButtonGrid()
{
    UINT nID = ::GetDlgCtrlID((HWND)::GetFocus());
    int row = (nID - IDC_BUTTON_GRID_00) / 5;
    int col = (nID - IDC_BUTTON_GRID_00) % 5;

    // 클릭한 버튼이 지뢰인지 확인
    if (isMine[row][col]) {
        GameOver();
        // 게임 오버 로직 등 추가 작성
    }
    else {
        // 지뢰가 없는 버튼을 클릭했을 때의 동작을 여기에 추가하세요.
        // 예: 주변 지뢰 개수 확인, 주변 버튼 열기 등
        int adjacentMines = CountAdjacentMines(row, col); // 주변 지뢰 개수 확인
        CString message;
        message.Format(_T("%d"), adjacentMines);
        m_btnGrid[row][col].SetWindowText(message); // 숫자를 버튼에 표시
        m_btnGrid[row][col].EnableWindow(FALSE);
        CheckGameWin();
        //TEST
    }
}

void CDlgMINE::CheckGameWin() {
    bool foundAllNonMines = true;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (!isMine[i][j] && m_btnGrid[i][j].IsWindowEnabled()) {
                foundAllNonMines = false;
                break;
            }
        }
        if (!foundAllNonMines) {
            break;
        }
    }

    if (foundAllNonMines) {
        GameWin();
    }
}
void CDlgMINE::GameWin() {
    CString timeStr;
    int minutes = m_elapsedTime / 60;
    int seconds = m_elapsedTime % 60;
    timeStr.Format(_T("게임 승리! 경과 시간: %02d:%02d"), minutes, seconds);
    MessageBox(timeStr, _T("게임 승리"), MB_OK | MB_ICONINFORMATION);

    int result = MessageBox(_T("게임을 승리하였습니다. 재도전 하시겠습니까?"), _T("게임 승리"), MB_YESNO | MB_ICONQUESTION);

    if (result == IDYES) {
        RestartGame();
    }
    else {
        MessageBox(_T("게임을 종료합니다."));
        EndDialog(0); // 다이얼로그 종료
    }
}
// 게임 종료 및 재시작 관련 함수 구현
void CDlgMINE::GameOver() {
    int result = MessageBox(_T("지뢰를 밟았습니다. 재도전 하시겠습니까?"), _T("게임 오버"), MB_YESNO | MB_ICONQUESTION);

    if (result == IDYES) {
        RestartGame();
    }
    else {
        MessageBox(_T("게임을 종료합니다."));
        EndDialog(0); // 다이얼로그 종료
    }
}

void CDlgMINE::RestartGame() {
    // 게임을 초기화하고 재시작하는 함수
    // TODO: 필요한 초기화 작업 수행
    m_elapsedSeconds = 0; // 경과 시간 초기화

    // 버튼 텍스트 초기화
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m_btnGrid[i][j].SetWindowText(_T(""));
            m_btnGrid[i][j].EnableWindow(TRUE); // 버튼 활성화
        }
    }

    // TODO: 지뢰 및 게임 데이터 초기화
    memset(isMine, FALSE, sizeof(isMine)); // isMine 배열 초기화

    // 지뢰 재배치
    srand(static_cast<unsigned int>(time(nullptr)));
    int minesPlaced = 0;
    while (minesPlaced < NUM_MINES) {
        int randomRow = rand() % 5;
        int randomCol = rand() % 5;

        if (!isMine[randomRow][randomCol]) {
            isMine[randomRow][randomCol] = TRUE;
            minesPlaced++;
        }
    }

    // 경과 시간을 업데이트합니다.
    UpdateElapsedTime();
}

