#pragma once
#include "afxcmn.h"


// Operation �Ի���

class Operation : public CDialogEx
{
	DECLARE_DYNAMIC(Operation)

public:
	Operation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Operation();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonChange();
};
