
// Experiment17.h : Experiment17 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment17App:
// �йش����ʵ�֣������ Experiment17.cpp
//

class CExperiment17App : public CWinApp
{
public:
	CExperiment17App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment17App theApp;
