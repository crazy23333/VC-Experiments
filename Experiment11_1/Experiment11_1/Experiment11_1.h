
// Experiment11_1.h : Experiment11_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment11_1App:
// �йش����ʵ�֣������ Experiment11_1.cpp
//

class CExperiment11_1App : public CWinApp
{
public:
	CExperiment11_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment11_1App theApp;
