
// Experiment6_1.h : Experiment6_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment6_1App:
// �йش����ʵ�֣������ Experiment6_1.cpp
//

class CExperiment6_1App : public CWinApp
{
public:
	CExperiment6_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment6_1App theApp;
