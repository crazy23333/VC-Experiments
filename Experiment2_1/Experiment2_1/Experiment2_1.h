
// Experiment2_1.h : Experiment2_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment2_1App:
// �йش����ʵ�֣������ Experiment2_1.cpp
//

class CExperiment2_1App : public CWinApp
{
public:
	CExperiment2_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment2_1App theApp;
