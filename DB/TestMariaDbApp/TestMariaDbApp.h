
// TestMariaDbApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestMariaDbAppApp:
// �йش����ʵ�֣������ TestMariaDbApp.cpp
//

class CTestMariaDbAppApp : public CWinAppEx
{
public:
	CTestMariaDbAppApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestMariaDbAppApp theApp;