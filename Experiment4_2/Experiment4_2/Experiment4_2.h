
// Experiment4_2.h : Experiment4_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment4_2App:
// �йش����ʵ�֣������ Experiment4_2.cpp
//

class CExperiment4_2App : public CWinApp
{
public:
	CExperiment4_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment4_2App theApp;
