
// ѧ���������ϵͳ������Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Cѧ���������ϵͳ������Dlg �Ի���
class Cѧ���������ϵͳ������Dlg : public CDialogEx
{
// ����
public:
	Cѧ���������ϵͳ������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_bnLogIn;
	CButton m_bnLogOut;
	CString m_strAccount;
	CString m_strPassword;
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnBnClickedButtonLogout();
	afx_msg void OnBnClickedButtonChangepassword();
};
