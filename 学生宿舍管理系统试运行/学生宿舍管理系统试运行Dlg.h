
// 学生宿舍管理系统试运行Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C学生宿舍管理系统试运行Dlg 对话框
class C学生宿舍管理系统试运行Dlg : public CDialogEx
{
// 构造
public:
	C学生宿舍管理系统试运行Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
