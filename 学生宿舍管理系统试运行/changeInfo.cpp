// changeInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ���������ϵͳ������.h"
#include "changeInfo.h"
#include "afxdialogex.h"


// changeInfo �Ի���

IMPLEMENT_DYNAMIC(changeInfo, CDialogEx)

changeInfo::changeInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(changeInfo::IDD, pParent)
	, m_strBednum(_T(""))
	, m_strBuildingnum(_T(""))
	, m_strHouseTel(_T(""))
	, m_strId(_T(""))
	, m_strMajor(_T(""))
	, m_strRemarks(_T(""))
	, m_strRoomtype(_T(""))
	, m_strStudentname(_T(""))
	, m_bMale(false)
{

}

changeInfo::~changeInfo()
{
}

void changeInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BEDNUM, m_strBednum);
	DDX_Text(pDX, IDC_EDIT_BUILDINGNUM, m_strBuildingnum);
	DDX_Text(pDX, IDC_EDIT_HOUSETEL, m_strHouseTel);
	DDX_Text(pDX, IDC_EDIT_ID, m_strId);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_REMARKS, m_strRemarks);
	DDX_Text(pDX, IDC_EDIT_ROOMTYPE, m_strRoomtype);
	DDX_Text(pDX, IDC_EDIT_STUDENTNAME, m_strStudentname);
}


BEGIN_MESSAGE_MAP(changeInfo, CDialogEx)
	ON_BN_CLICKED(IDC_MALE, &changeInfo::OnBnClickedMale)
	ON_BN_CLICKED(IDC_FEMALE, &changeInfo::OnBnClickedFemale)
	ON_BN_CLICKED(IDOK, &changeInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// changeInfo ��Ϣ�������


void changeInfo::OnBnClickedMale()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bMale=TRUE;
}


void changeInfo::OnBnClickedFemale()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bMale=FALSE;
}


BOOL changeInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

if(!m_bMale)
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_FEMALE);
	else
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_MALE);
	UpdateData(FALSE);      //���ؼ���ֵ�������
	return TRUE;
}


void changeInfo::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
