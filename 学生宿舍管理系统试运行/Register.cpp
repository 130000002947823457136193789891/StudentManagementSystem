// Register.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���������ϵͳ������.h"
#include "Register.h"
#include "afxdialogex.h"
#include "account.h"


// CRegister �Ի���

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


// CRegister ��Ϣ�������


void CRegister::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	Caccount cSet;
	UpdateData();
	m_strUserName.TrimLeft ();
	m_strPassword0.TrimLeft ();
	if(!m_strPassword0.IsEmpty()&&!m_strUserName.IsEmpty()){
		if(m_strNewPassword.IsEmpty())
		AfxMessageBox(TEXT("��ȷ������"));
	else if(m_strPassword0!=m_strNewPassword &&!m_strNewPassword.IsEmpty())
		MessageBox("������ȷ������");
	else if(m_strPassword0 ==m_strNewPassword ){
		cSet.m_strFilter.Format("account='%s'",m_strUserName );
		cSet.Open();//�򿪼�¼��
		if(!cSet.IsEOF()){ //����򿪼�¼���м�¼
			MessageBox("�û����Ѵ��ڣ��������");
			cSet.Close();
		}
		else {
			MessageBox("ע��ɹ���");
			CDialogEx::OnOK();
		}
	}

	}
	else if(m_strPassword0 .IsEmpty()&&m_strUserName.IsEmpty())
		AfxMessageBox(TEXT("�û��������벻��Ϊ�գ�"));
	else if(m_strPassword0 .IsEmpty())
	AfxMessageBox(TEXT("���벻��Ϊ�գ�"));
	else if(m_strUserName.IsEmpty())
		AfxMessageBox(TEXT("�û�������Ϊ��"));
}
