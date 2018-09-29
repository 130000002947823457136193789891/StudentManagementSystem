// Register.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍管理系统试运行.h"
#include "Register.h"
#include "afxdialogex.h"
#include "account.h"


// CRegister 对话框

IMPLEMENT_DYNAMIC(CRegister, CDialogEx)

CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegister::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPassword0(_T(""))
	, m_strNewPassword(_T(""))
{

}

CRegister::~CRegister()
{
}

void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NEWACCOUNT, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword0);
	DDX_Text(pDX, IDC_EDIT_PASSWORDCONFIRM, m_strNewPassword);
}


BEGIN_MESSAGE_MAP(CRegister, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRegister::OnBnClickedOk)
END_MESSAGE_MAP()


// CRegister 消息处理程序


void CRegister::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	Caccount cSet;
	UpdateData();
	m_strUserName.TrimLeft ();
	m_strPassword0.TrimLeft ();
	if(!m_strPassword0.IsEmpty()&&!m_strUserName.IsEmpty()){
		if(m_strNewPassword.IsEmpty())
		AfxMessageBox(TEXT("请确认密码"));
	else if(m_strPassword0!=m_strNewPassword &&!m_strNewPassword.IsEmpty())
		MessageBox("请重新确认密码");
	else if(m_strPassword0 ==m_strNewPassword ){
		cSet.m_strFilter.Format("account='%s'",m_strUserName );
		cSet.Open();//打开记录集
		if(!cSet.IsEOF()){ //如果打开记录集有记录
			MessageBox("用户名已存在，请更换！");
			cSet.Close();
		}
		else {
			MessageBox("注册成功！");
			CDialogEx::OnOK();
		}
	}

	}
	else if(m_strPassword0 .IsEmpty()&&m_strUserName.IsEmpty())
		AfxMessageBox(TEXT("用户名，密码不能为空！"));
	else if(m_strPassword0 .IsEmpty())
	AfxMessageBox(TEXT("密码不能为空！"));
	else if(m_strUserName.IsEmpty())
		AfxMessageBox(TEXT("用户名不能为空"));
}
