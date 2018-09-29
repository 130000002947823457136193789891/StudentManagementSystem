// changePassword.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍管理系统试运行.h"
#include "changePassword.h"
#include "afxdialogex.h"
#include "account.h"


// changePassword 对话框

IMPLEMENT_DYNAMIC(changePassword, CDialogEx)

changePassword::changePassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(changePassword::IDD, pParent)
	, m_strConfirmPassword(_T(""))
	, m_strNewPassword(_T(""))
	, m_old(_T(""))
	, m_strAccount(_T(""))
{

}

changePassword::~changePassword()
{
}

void changePassword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CONFIRMPASSWORD, m_strConfirmPassword);
	DDX_Text(pDX, IDC_EDIT_NEWPASSWORD, m_strNewPassword);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_old);
	DDX_Text(pDX, IDC_EDITACCOUNT, m_strAccount);
}


BEGIN_MESSAGE_MAP(changePassword, CDialogEx)
	ON_BN_CLICKED(IDOK, &changePassword::OnBnClickedOk)
END_MESSAGE_MAP()


// changePassword 消息处理程序


void changePassword::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Caccount cSet;
	if(!m_strNewPassword.IsEmpty()&&!m_old.IsEmpty ()&&m_strConfirmPassword.IsEmpty()&&!m_strAccount.IsEmpty () ){
		cSet.Open();
		if(cSet.IsEOF()){
			MessageBox("用户名不存在");
				cSet.Close();
		}
		else 
		{
			cSet.Close ();
			cSet.m_strFilter.Format ("password='%s'",m_old);
			cSet.Open();
			if(cSet.IsEOF ())    //如果打开记录集无记录
			{
				MessageBox("旧密码错误！");
				cSet.Close();
			}
			else{
				if(m_strNewPassword==m_old)
					MessageBox("新旧密码不能相同！");
				else {
					if(m_strNewPassword !=m_old)
						MessageBox("请重新确认密码！");
					else{
						MessageBox("修改成功！");
						CDialogEx::OnOK();
					}
				}

			}
		}
	}

	else 
		MessageBox("密码不能为空！");
}
