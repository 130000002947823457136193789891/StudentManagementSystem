// Operation.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍管理系统试运行.h"
#include "Operation.h"
#include "afxdialogex.h"
#include "student0.h"
#include "addDlg.h"
#include "account.h"
#include "changeInfo.h"



// Operation 对话框

IMPLEMENT_DYNAMIC(Operation, CDialogEx)

Operation::Operation(CWnd* pParent /*=NULL*/)
	: CDialogEx(Operation::IDD, pParent)
{

}

Operation::~Operation()
{
}

void Operation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}


BEGIN_MESSAGE_MAP(Operation, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Operation::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Operation::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &Operation::OnBnClickedButtonChange)
END_MESSAGE_MAP()


// Operation 消息处理程序


BOOL Operation::OnInitDialog()
{
	
// TODO:  在此添加额外的初始化
	CDialog::OnInitDialog ();
	CString strHeader[]={"学号","学生姓名","性别","入学年份","专业","宿舍类型","楼号","房间号","宿舍电话","备注"};
	int nLong[]={100,100,100,100,100,120,100,100,100,100};
	for(int nCol=0;nCol<sizeof(strHeader)/sizeof(CString);nCol++)
		m_listCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);

	//创建列表项
	Cstudent0 sSet;
	sSet.Open();
	int nItem=0;
	CString str;
	while(!sSet.IsEOF()){
		for(UINT i=0;i<9;i++){
		sSet.GetFieldValue(i,str);
		if(i==0)
			m_listCtrl.InsertItem(nItem,str);
		else
			m_listCtrl.SetItemText(nItem,i,str);}
	/*
	m_listCtrl.SetItemText(nItem,6,sSet.m_Studentname );
	*/
		sSet.MoveNext ();
	}
    sSet.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
}


void Operation::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Cstudent0 sSet;
	addDlg dlg;
	if(dlg.DoModal ()==IDOK){
		sSet.Open();
		sSet.AddNew ();
		if (dlg.m_bMale==1)
			sSet.m_Sex="男";
		else
			sSet.m_Sex="女";
		sSet.m_Studentname =dlg.m_strStudentname ;
		sSet.m_Id =dlg.m_strId ;
		//sSet.m_Startyear =dlg.m_time;
		sSet.m_Major =dlg.m_strMajor ;
		sSet .m_Roomtype =dlg.m_strRoomtype ;
		//sSet .m_Buildingnum =dlg.m_nBuildingnum ;
		//sSet .m_Bednum =dlg.m_nBednum ;
		sSet .m_Housetel =dlg.m_strHouseTel ;
		sSet .m_Remarks =dlg.m_strRemarks ;
		sSet .Update ();
		sSet .Requery ();


	}

}


void Operation::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos;
	pos=m_listCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{MessageBox("还没有选中列表项");
	return;}
	int nItem=m_listCtrl.GetNextSelectedItem (pos);
	CString m_del_id1=m_listCtrl.GetItemText(nItem,0);
	//CString m_del_id2=m_listCtrl.GetItemText(nItem,6);
	//CString m_del_id3=m_listCtrl.GetItemText(nItem,8);
	if(IDYES==MessageBox("确定要删除吗？","警告",MB_ICONWARNING|MB_YESNO))
	{
		m_listCtrl.DeleteItem(nItem);
	}
	Cstudent0 sSet;
	sSet.m_strFilter.Format("ID='%s'",m_del_id1);
	//MessageBox(m_del_id1);
	sSet.Open();
	CRecordsetStatus status1;
	sSet.GetStatus(status1);
	sSet.Delete();
	if(status1.m_lCurrentRecord ==0)
		sSet.MoveNext ();
	else
		sSet.MoveFirst ();

	UpdateData(FALSE);      //将控件的记录传到变量中
}


void Operation::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos;
	pos=m_listCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL){
		MessageBox("还没有选中列表项");
		return;

	}
	int nItem=m_listCtrl.GetNextSelectedItem (pos);
	changeInfo dlg;
	dlg.m_strId=m_listCtrl.GetItemText(nItem,0);
	dlg.m_strStudentname=m_listCtrl.GetItemText(nItem,1);
		//dlg.m_=m_listCtrl.GetItemText(nItem,2);
			//dlg.m_strStudentname=m_listCtrl.GetItemText(nItem,3);
			dlg.m_strMajor=m_listCtrl.GetItemText(nItem,4);
		dlg.m_strRoomtype=m_listCtrl.GetItemText(nItem,5);
		dlg.m_strBuildingnum=m_listCtrl.GetItemText(nItem,6);
		dlg.m_strBednum=m_listCtrl.GetItemText(nItem,7);
			dlg.m_strHouseTel=m_listCtrl.GetItemText(nItem,8);
			dlg.m_strRemarks=m_listCtrl.GetItemText(nItem,9);
	Caccount pSet;
	Cstudent0 sSet;
	if(dlg.DoModal ()==IDOK)
	{
		sSet.m_strFilter.Format("ID='%s'",m_listCtrl.GetItemText(nItem,0));
		sSet.Open();
		sSet.Edit();
		sSet.m_Studentname =dlg.m_strStudentname ;
		if(dlg.m_bMale ==1)
			sSet.m_Sex ="男";
		else
			sSet.m_Sex ="女";
		sSet.Update();
		sSet.Requery ();
	}
}
