
// Experiment15_2.h : Experiment15_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment15_2App:
// �йش����ʵ�֣������ Experiment15_2.cpp
//

class CExperiment15_2App : public CWinApp
{
public:
	CExperiment15_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment15_2App theApp;
