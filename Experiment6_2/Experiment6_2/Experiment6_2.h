
// Experiment6_2.h : Experiment6_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment6_2App:
// �йش����ʵ�֣������ Experiment6_2.cpp
//

class CExperiment6_2App : public CWinApp
{
public:
	CExperiment6_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment6_2App theApp;
