
// Experiment2_3.h : Experiment2_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment2_3App:
// �йش����ʵ�֣������ Experiment2_3.cpp
//

class CExperiment2_3App : public CWinApp
{
public:
	CExperiment2_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment2_3App theApp;
