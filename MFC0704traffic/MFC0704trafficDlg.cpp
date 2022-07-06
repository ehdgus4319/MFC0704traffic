
// MFC0704trafficDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC0704traffic.h"
#include "MFC0704trafficDlg.h"
#include "afxdialogex.h"
#include "C_AccidentData.h"
#include <fstream>
#include <string>
#include <vector>
#include "CNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

int j = 0;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC0704trafficDlg 대화 상자



CMFC0704trafficDlg::CMFC0704trafficDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC0704TRAFFIC_DIALOG, pParent)
	, m_search_edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC0704trafficDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_LoadList);
	DDX_Text(pDX, IDC_EDIT1, m_search_edit);
}

BEGIN_MESSAGE_MAP(CMFC0704trafficDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC0704trafficDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC0704trafficDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFC0704trafficDlg 메시지 처리기

BOOL CMFC0704trafficDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_LoadList.InsertColumn(0, _T("시도"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(1, _T("시군구"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(2, _T("횡당보도상"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(3, _T("횡단보도부근"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(4, _T("터널안"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(5, _T("교량위"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(6, _T("기타단일로"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(7, _T("교차로내"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(8, _T("교차로부근"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(9, _T("건널목"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(10, _T("기타불명"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(11, _T("고가도로위"), LVCFMT_CENTER, 100);
	m_LoadList.InsertColumn(12, _T("지하도로내"), LVCFMT_CENTER, 100);
	m_LoadList.SetExtendedStyle(m_LoadList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	ifstream data("data.csv");
	string line;
	int count = m_LoadList.GetItemCount();

	while (getline(data, line))
	{
		stringstream lineStream(line); //한줄의 데이터를 가지고 사용
		string cell;
		CString cell2;

		C_AccidentData tmp;

		UpdateData(true);
		for (int i = 0; i < 13; i++)
		{
			getline(lineStream, cell, ',');
			cell2 = CA2CT(cell.c_str());
			if (i == 0)
			{
			
				tmp.state = cell2;
				m_LoadList.SetItem(count, 1, LVIF_TEXT, tmp.city, 0, 0, 0,
					0);
			}
			else
			{
				tmp.data_list[i - 2] = cell2;
				m_LoadList.SetItem(count, i, LVIF_TEXT, tmp.data_list[i - 2], 0, 0,
					0, 0);
			}
		}
		j++;

		dataList.push_back(tmp);

	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFC0704trafficDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFC0704trafficDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFC0704trafficDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC0704trafficDlg::OnBnClickedButton1()  // 로드 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
UpdateData(true);
	m_LoadList.DeleteAllItems();
	
	int info = m_LoadList.GetItemCount();
	int count = 0;
	for (int i = 0; i < 229; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if(dataList[i].state )
			{

				if (j == 0)
				{
					m_LoadList.InsertItem(info, dataList[count].state);
				}
				if (j == 1)
				{
					m_LoadList.SetItem(info, LVIF_TEXT, 1, dataList[count].city, 0, 0, 0, 0);
				}
				else
				{
					m_LoadList.SetItem(info, j, LVIF_TEXT, dataList[count].data_list[j - 2], 0, 0, 0, 0);
				}

			}
		}
		count++;
	}

}


void CMFC0704trafficDlg::OnBnClickedButton2()  // 검색 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CNewDlg child;

	vector< C_AccidentData> fliltered;
	
	m_LoadList.DeleteAllItems();
	UpdateData(true);
	
	int count = 0;
	for (int i = 0; i < 229; i++)
	{
		C_AccidentData tmp;
		for (int j = 0; j < 13; j++)
		{
			if (dataList[i].state == m_search_edit)
			{

				tmp = dataList[i];
			}
			else if (dataList[i].city == m_search_edit)
			{

				tmp = dataList[i];
			}
		}
		count++;
		if(tmp.state != "")
			fliltered.push_back(tmp);
	}
	child.SetListControl(fliltered);
	child.DoModal();
}



