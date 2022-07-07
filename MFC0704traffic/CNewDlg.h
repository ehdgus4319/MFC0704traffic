#pragma once
#include "C_AccidentData.h"
#include <vector>

// CNewDlg 대화 상자

class CNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CNewDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CNewDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NewDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	void SetListControl(vector< C_AccidentData> ptr);
	CListCtrl m_SearchedListBox;
	virtual BOOL OnInitDialog();
	CString m_text;
	int m_count_new;
	//C_AccidentData* dataList_kid;
	vector< C_AccidentData> dataList_kid;
	afx_msg void OnBnClickedButton1();
};