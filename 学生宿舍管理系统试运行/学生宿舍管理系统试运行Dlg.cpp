
// ѧ���������ϵͳ������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���������ϵͳ������.h"
#include "ѧ���������ϵͳ������Dlg.h"
#include "afxdialogex.h"
#include "account.h"
#include "Register.h"
#include "changePassword.h"
#include "Operation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cѧ���������ϵͳ������Dlg �Ի���



Cѧ���������ϵͳ������Dlg::Cѧ���������ϵͳ������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cѧ���������ϵͳ������Dlg::IDD, pParent)
	, m_strAccount(_T(""))
	, m_strPassword(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cѧ���������ϵͳ������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_LOGIN, m_bnLogIn);
	DDX_Control(pDX, IDC_BUTTON_LOGOUT, m_bnLogOut);
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, m_strAccount);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
}

BEGIN_MESSAGE_MAP(Cѧ���������ϵͳ������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &Cѧ���������ϵͳ������Dlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &Cѧ���������ϵͳ������Dlg::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_CHANGEPASSWORD, &Cѧ���������ϵͳ������Dlg::OnBnClickedButtonChangepassword)
END_MESSAGE_MAP()


// Cѧ���������ϵͳ������Dlg ��Ϣ�������

BOOL Cѧ���������ϵͳ������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cѧ���������ϵͳ������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cѧ���������ϵͳ������Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cѧ���������ϵͳ������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cѧ���������ϵͳ������Dlg::OnBnClickedButtonLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Caccount pSet;
	UpdateData();
	m_strAccount.TrimLeft();
	m_strPassword.TrimLeft();
	if(m_strAccount.IsEmpty()||m_strPassword.IsEmpty())
	{
		AfxMessageBox(TEXT("�˺ţ����벻��Ϊ�գ�"));
		return;
	}
	if(pSet.IsOpen())
		pSet.Close();
	pSet.m_strFilter .Format ("account='%s'",m_strAccount);
	pSet.Open();
	if(!pSet.IsEOF())        //�����¼����Ϊ��
	{
		pSet.Close();
		pSet.m_strFilter .Format ("account='%s'and password='%s'",m_strAccount,m_strPassword);
		pSet.Open();
		if(!pSet.IsEOF())
		{
			MessageBox("��¼�ɹ�");
			pSet.Close();
			OnCancel();
			Operation dlg;
			//Cѧ������Dlg dlg;
			dlg.DoModal ();

		}
		else
			MessageBox("�������");
	}
}


void Cѧ���������ϵͳ������Dlg::OnBnClickedButtonLogout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRegister dlg;
	dlg.DoModal ();
}


void Cѧ���������ϵͳ������Dlg::OnBnClickedButtonChangepassword()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Caccount cSet;
	changePassword dlg;
	if(dlg.DoModal ()==IDOK){
		cSet.Open();
		cSet.Edit();
		cSet.m_password =dlg.m_strNewPassword ;     //ȷ�������뼴����������ֵ
		cSet.Update();
		cSet.Requery ();

	}
}
