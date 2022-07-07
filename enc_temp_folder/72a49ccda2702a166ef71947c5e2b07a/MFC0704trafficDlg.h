
// MFC0704trafficDlg.h: 헤더 파일
//

#pragma once
#include "C_AccidentData.h"
#include <vector>

using std::vector;

// CMFC0704trafficDlg 대화 상자
class CMFC0704trafficDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMFC0704trafficDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC0704TRAFFIC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//C_AccidentData** data;
	vector< C_AccidentData> dataList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_LoadList;
	CString m_search_edit;
	CListCtrl m_SumList;
	// CString str
	void SetEditBox(const CString str);
};