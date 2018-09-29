// student0.h : Cstudent0 类的实现



// Cstudent0 实现

// 代码生成在 2018年7月15日, 11:06

#include "stdafx.h"
#include "student0.h"
IMPLEMENT_DYNAMIC(Cstudent0, CRecordset)

Cstudent0::Cstudent0(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Id = "";
	m_Studentname = "";
	m_Sex = "";
	m_Startyear = "";
	m_Major = "";
	m_Roomtype = "";
	m_Buildingnum = 0;
	m_Bednum = 0;
	m_Housetel = "";
	m_Remarks = "";
	m_nFields = 10;
	m_nDefaultType = snapshot;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Cstudent0::GetDefaultConnect()
{
	return _T("DSN=StudentDorm;SERVER=localhost;UID=root;PWD=13508459029;DATABASE=stuinfo;PORT=3306");
}

CString Cstudent0::GetDefaultSQL()
{
	return _T("[student0]");
}

void Cstudent0::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Id]"), m_Id);
	RFX_Text(pFX, _T("[Studentname]"), m_Studentname);
	RFX_Text(pFX, _T("[Sex]"), m_Sex);
	RFX_Text(pFX, _T("[Startyear]"), m_Startyear);
	RFX_Text(pFX, _T("[Major]"), m_Major);
	RFX_Text(pFX, _T("[Roomtype]"), m_Roomtype);
	RFX_Long(pFX, _T("[Buildingnum]"), m_Buildingnum);
	RFX_Long(pFX, _T("[Bednum]"), m_Bednum);
	RFX_Text(pFX, _T("[Housetel]"), m_Housetel);
	RFX_Text(pFX, _T("[Remarks]"), m_Remarks);

}
/////////////////////////////////////////////////////////////////////////////
// Cstudent0 诊断

#ifdef _DEBUG
void Cstudent0::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cstudent0::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


