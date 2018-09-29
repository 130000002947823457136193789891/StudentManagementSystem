// student0.h : Cstudent0 ������

#pragma once

// ���������� 2018��7��15��, 11:06

class Cstudent0 : public CRecordset
{
public:
	Cstudent0(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cstudent0)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringA	m_Id;
	CStringA	m_Studentname;
	CStringA	m_Sex;
	CStringA	m_Startyear;
	CStringA	m_Major;
	CStringA	m_Roomtype;
	long	m_Buildingnum;
	long	m_Bednum;
	CStringA	m_Housetel;
	CStringA	m_Remarks;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


