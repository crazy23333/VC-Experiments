
// Experiment4_3.h : Experiment4_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment4_3App:
// �йش����ʵ�֣������ Experiment4_3.cpp
//

class CExperiment4_3App : public CWinApp
{
public:
	CExperiment4_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment4_3App theApp;
