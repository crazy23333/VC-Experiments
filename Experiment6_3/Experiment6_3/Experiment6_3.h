
// Experiment6_3.h : Experiment6_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment6_3App:
// �йش����ʵ�֣������ Experiment6_3.cpp
//

class CExperiment6_3App : public CWinApp
{
public:
	CExperiment6_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment6_3App theApp;
