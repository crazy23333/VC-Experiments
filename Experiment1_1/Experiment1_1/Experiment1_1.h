
// Experiment1_1.h : Experiment1_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment1_1App:
// �йش����ʵ�֣������ Experiment1_1.cpp
//

class CExperiment1_1App : public CWinApp
{
public:
	CExperiment1_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment1_1App theApp;
