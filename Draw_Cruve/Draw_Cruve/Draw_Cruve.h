
// Draw_Cruve.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDraw_CruveApp:
// �йش����ʵ�֣������ Draw_Cruve.cpp
//

class CDraw_CruveApp : public CWinApp
{
public:
	CDraw_CruveApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDraw_CruveApp theApp;