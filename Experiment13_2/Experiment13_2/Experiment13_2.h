
// Experiment13_2.h : Experiment13_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment13_2App:
// �йش����ʵ�֣������ Experiment13_2.cpp
//

class CExperiment13_2App : public CWinApp
{
public:
	CExperiment13_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment13_2App theApp;
