// account.h : Caccount ���ʵ��



// Caccount ʵ��

// ���������� 2018��7��15��, 10:28

#include "stdafx.h"
#include "account.h"
IMPLEMENT_DYNAMIC(Caccount, CRecordset)

Caccount::Caccount(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_account = "";
	m_password = "";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Caccount::GetDefaultConnect()
{
	return _T("DSN=StudentDorm;SERVER=localhost;UID=root;PWD=13508459029;DATABASE=stuinfo;PORT=3306");
}

CString Caccount::GetDefaultSQL()
{
	return _T("[account]");
}

void Caccount::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[account]"), m_account);
	RFX_Text(pFX, _T("[password]"), m_password);

}
/////////////////////////////////////////////////////////////////////////////
// Caccount ���

#ifdef _DEBUG
void Caccount::AssertValid() const
{
	CRecordset::AssertValid();
}

void Caccount::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


