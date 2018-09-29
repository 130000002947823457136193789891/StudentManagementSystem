// changeInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍管理系统试运行.h"
#include "changeInfo.h"
#include "afxdialogex.h"


// changeInfo 对话框

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


// changeInfo 消息处理程序


void changeInfo::OnBnClickedMale()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bMale=TRUE;
}


void changeInfo::OnBnClickedFemale()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bMale=FALSE;
}


BOOL changeInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

if(!m_bMale)
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_FEMALE);
	else
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_MALE);
	UpdateData(FALSE);      //将控件的值传入变量
	return TRUE;
}


void changeInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
