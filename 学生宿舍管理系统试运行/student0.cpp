// student0.h : Cstudent0 ���ʵ��



// Cstudent0 ʵ��

// ���������� 2018��7��15��, 11:06

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
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// Cstudent0 ���

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


