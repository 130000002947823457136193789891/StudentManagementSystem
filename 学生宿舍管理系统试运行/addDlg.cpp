// addDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍管理系统试运行.h"
#include "addDlg.h"
#include "afxdialogex.h"
#include "student0.h"


// addDlg 对话框

IMPLEMENT_DYNAMIC(addDlg, CDialogEx)

addDlg::addDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(addDlg::IDD, pParent)
	, m_bMale(false)
	, m_nBednum()
	, m_nBuildingnum()
	, m_strHouseTel(_T(""))
	, m_strId(_T(""))
	, m_strMajor(_T(""))
	, m_strRemarks(_T(""))
	, m_strRoomtype(_T(""))
	, m_strStudentname(_T(""))
	/* , m_strBuildingnum(_T(""))
	, m_nBednum(_T(""))
	, m_nBuildingnum(_T("")*/
	
{

}

addDlg::~addDlg()
{
}

void addDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_BED, m_nBednum);
	//  DDX_Text(pDX, IDC_EDIT_BUILDINGNUM, m_nBuildingnum);
	DDX_Text(pDX, IDC_EDIT_HOUSETEL, m_strHouseTel);
	DDX_Text(pDX, IDC_EDIT_ID, m_strId);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_REMARKS, m_strRemarks);
	DDX_Text(pDX, IDC_EDIT_ROOMTYPE, m_strRoomtype);
	DDX_Text(pDX, IDC_EDIT_STUDENTNAME, m_strStudentname);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_time);
	//  DDX_Text(pDX, IDC_EDIT_BED, m_strBuildingnum);
	DDX_Text(pDX, IDC_EDIT_BED, m_nBednum);
	DDX_Text(pDX, IDC_EDIT_BUILDINGNUM, m_nBuildingnum);
}


BEGIN_MESSAGE_MAP(addDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MALE, &addDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_FEMALE, &addDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, &addDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// addDlg 消息处理程序


void addDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bMale=TRUE;
}


void addDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bMale=FALSE;
}


BOOL addDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
/*
#5312

	return TRUE;  // return TRUE unless you set the focus to a control
#5313

#5312

	return TRUE;  // return TRUE unless you set the focus to a 
	
#5313
	*/
	// TODO:  在此添加额外的初始化
	if(!m_bMale)
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_FEMALE);
	else
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_MALE);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	/*
#5313
	return TRUE;  // return TRUE unless you set the focus to a control
#5313
	// 异常: OCX 属性页应返回 FALSE
	*/
}


void addDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Cstudent0 sSet;
	UpdateData();    //将控件中的信息传入到变量中去
	m_strStudentname.TrimLeft ();
	m_strId.TrimLeft ();
	m_strMajor .TrimLeft ();
	m_strRoomtype .TrimLeft ();
	m_nBuildingnum .TrimLeft();
	m_nBednum.TrimLeft();
	m_strHouseTel .TrimLeft ();
	m_strRemarks .TrimLeft ();

	if(m_strStudentname .IsEmpty ()||m_strId .IsEmpty ()||m_strMajor.IsEmpty ()||
		m_strRoomtype .IsEmpty ()||m_nBuildingnum .IsEmpty ()||m_nBednum .IsEmpty ()||
		m_strHouseTel .IsEmpty ()||m_strRemarks .IsEmpty ())
		MessageBox("不能有空项！");
	else
	{
		sSet.m_strFilter .Format("ID='%s'",m_strId);
		sSet.Open();//打开记录集
		if(!sSet.IsEOF())
		{
			//already recorded
			MessageBox("该ID信息已经添加。");
			sSet.Close();
		}
		else
		{
			MessageBox("添加成功！");
			CDialog::OnOK();
		}
	}


		
	CDialogEx::OnOK();
}
