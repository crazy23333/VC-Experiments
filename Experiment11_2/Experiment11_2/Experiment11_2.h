
// Experiment11_2.h : Experiment11_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment11_2App:
// �йش����ʵ�֣������ Experiment11_2.cpp
//

class CExperiment11_2App : public CWinApp
{
public:
	CExperiment11_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment11_2App theApp;
