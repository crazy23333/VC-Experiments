
// Experiment13_1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CExperiment13_1App: 
// �йش����ʵ�֣������ Experiment13_1.cpp
//

class CExperiment13_1App : public CWinApp
{
public:
	CExperiment13_1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CExperiment13_1App theApp;