// changePassword.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���������ϵͳ������.h"
#include "changePassword.h"
#include "afxdialogex.h"
#include "account.h"


// changePassword �Ի���

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


// changePassword ��Ϣ�������


void changePassword::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Caccount cSet;
	if(!m_strNewPassword.IsEmpty()&&!m_old.IsEmpty ()&&m_strConfirmPassword.IsEmpty()&&!m_strAccount.IsEmpty () ){
		cSet.Open();
		if(cSet.IsEOF()){
			MessageBox("�û���������");
				cSet.Close();
		}
		else 
		{
			cSet.Close ();
			cSet.m_strFilter.Format ("password='%s'",m_old);
			cSet.Open();
			if(cSet.IsEOF ())    //����򿪼�¼���޼�¼
			{
				MessageBox("���������");
				cSet.Close();
			}
			else{
				if(m_strNewPassword==m_old)
					MessageBox("�¾����벻����ͬ��");
				else {
					if(m_strNewPassword !=m_old)
						MessageBox("������ȷ�����룡");
					else{
						MessageBox("�޸ĳɹ���");
						CDialogEx::OnOK();
					}
				}

			}
		}
	}

	else 
		MessageBox("���벻��Ϊ�գ�");
}
