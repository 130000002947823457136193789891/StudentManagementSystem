#pragma once


// changePassword �Ի���

class changePassword : public CDialogEx
{
	DECLARE_DYNAMIC(changePassword)

public:
	changePassword(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~changePassword();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strConfirmPassword;
	CString m_strNewPassword;
	CString m_old;
	CString m_strAccount;
	afx_msg void OnBnClickedOk();
};
