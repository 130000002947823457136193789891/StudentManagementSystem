#pragma once
#include "afxdtctl.h"


// addDlg �Ի���

class addDlg : public CDialogEx
{
	DECLARE_DYNAMIC(addDlg)

public:
	addDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~addDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	bool m_bMale;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	virtual BOOL OnInitDialog();
//	int m_nBednum;
//	int m_nBuildingnum;
	CString m_strHouseTel;
	CString m_strId;
	CString m_strMajor;
	CString m_strRemarks;
	CString m_strRoomtype;
	CString m_strStudentname;
	CDateTimeCtrl m_time;
	afx_msg void OnBnClickedOk();
//	CString m_strBuildingnum;
	CString m_nBednum;
	CString m_nBuildingnum;
};
