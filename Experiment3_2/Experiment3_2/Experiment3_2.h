
// Experiment3_2.h : Experiment3_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment3_2App:
// �йش����ʵ�֣������ Experiment3_2.cpp
//

class CExperiment3_2App : public CWinApp
{
public:
	CExperiment3_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment3_2App theApp;
