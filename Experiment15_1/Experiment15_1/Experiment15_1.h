
// Experiment15_1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExperiment15_1App: 
// �йش����ʵ�֣������ Experiment15_1.cpp
//

class CExperiment15_1App : public CWinApp
{
public:
	CExperiment15_1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExperiment15_1App theApp;