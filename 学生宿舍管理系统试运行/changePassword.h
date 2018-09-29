#pragma once


// changePassword 对话框

class changePassword : public CDialogEx
{
	DECLARE_DYNAMIC(changePassword)

public:
	changePassword(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~changePassword();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strConfirmPassword;
	CString m_strNewPassword;
	CString m_old;
	CString m_strAccount;
	afx_msg void OnBnClickedOk();
};
