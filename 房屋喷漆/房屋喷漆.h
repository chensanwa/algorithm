
// ��������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "gdiplusinit.h"


// C��������App:
// �йش����ʵ�֣������ ��������.cpp
//

class C��������App : public CWinApp
{
public:
	C��������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	GdiplusStartupInput GdiInput;
	ULONG_PTR GdiToken;
	int ExitInstance(void);
};

extern C��������App theApp;