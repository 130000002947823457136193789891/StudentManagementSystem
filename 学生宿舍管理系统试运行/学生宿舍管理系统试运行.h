
// ѧ���������ϵͳ������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cѧ���������ϵͳ������App:
// �йش����ʵ�֣������ ѧ���������ϵͳ������.cpp
//

class Cѧ���������ϵͳ������App : public CWinApp
{
public:
	Cѧ���������ϵͳ������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cѧ���������ϵͳ������App theApp;