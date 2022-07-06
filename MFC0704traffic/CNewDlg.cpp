// CNewDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC0704traffic.h"
#include "CNewDlg.h"
#include "afxdialogex.h"
#include "C_AccidentData.h"
#include "MFC0704traffic.h"
#include "MFC0704trafficDlg.h"
#include "MFC0704traffic.h"
#include "MFC0704trafficDlg.h"
#include "afxdialogex.h"
#include "C_AccidentData.h"
#include <fstream>
#include <string>
#include <vector>

// CNewDlg 대화 상자

vector< C_AccidentData> str_data(229);
IMPLEMENT_DYNAMIC(CNewDlg, CDialogEx)

CNewDlg::CNewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NewDlg, pParent), m_text(_T(""))
{
	
}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SearchedListBox);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialogEx)
END_MESSAGE_MAP()


// CNewDlg 메시지 처리기

BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	m_SearchedListBox.InsertColumn(0, _T("시도"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(1, _T("시군구"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(2, _T("횡당보도상"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(3, _T("횡단보도부근"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(4, _T("터널안"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(5, _T("교량위"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(6, _T("기타단일로"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(7, _T("교차로내"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(8, _T("교차로부근"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(9, _T("건널목"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(10, _T("기타불명"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(11, _T("고가도로위"), LVCFMT_CENTER, 100);
	m_SearchedListBox.InsertColumn(12, _T("지하도로내"), LVCFMT_CENTER, 100);
	m_SearchedListBox.SetExtendedStyle(m_SearchedListBox.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
//vector< C_AccidentData> str(229);
void CNewDlg::SetListControl(C_AccidentData data_kid)
{
	// TODO: 여기에 구현 코드 추가.

	UpdateData(true);
	m_SearchedListBox.DeleteAllItems();
	dataList_kid = data_kid;
	int info_count = m_SearchedListBox.GetItemCount();
	
	m_count_new = m_SearchedListBox.GetItemCount();
	for (int i = 0; i < 229; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (str_data[i].state == m_text)
			{

				if (j == 0)
				{
					m_SearchedListBox.InsertItem(info_count, str_data[info_count].state);
				}
				if (j == 1)
				{
					m_SearchedListBox.SetItem(info_count, LVIF_TEXT, 1, str_data[info_count].city, 0, 0, 0, 0);
				}
				else
				{
					m_SearchedListBox.SetItem(info_count, j, LVIF_TEXT, str_data[info_count].data_list[j - 2], 0, 0, 0, 0);
				}

			}
			else if (str_data[i].city == m_text)
			{

				if (j == 0)
				{
					m_SearchedListBox.InsertItem(info_count, str_data[info_count].state);
				}
				if (j == 1)
				{
					m_SearchedListBox.SetItem(info_count, LVIF_TEXT, 1, str_data[info_count].city, 0, 0, 0, 0);
				}
				else
				{
					m_SearchedListBox.SetItem(info_count, j, LVIF_TEXT, str_data[info_count].data_list[j - 2], 0, 0, 0, 0);
				}

			}
		}
		m_count_new++;
	}
	
}



