
// Experiment1_3.h : Experiment1_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment1_3App:
// �йش����ʵ�֣������ Experiment1_3.cpp
//

class CExperiment1_3App : public CWinApp
{
public:
	CExperiment1_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment1_3App theApp;
