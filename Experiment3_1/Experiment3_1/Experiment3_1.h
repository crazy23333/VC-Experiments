
// Experiment3_1.h : Experiment3_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment3_1App:
// �йش����ʵ�֣������ Experiment3_1.cpp
//

class CExperiment3_1App : public CWinApp
{
public:
	CExperiment3_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment3_1App theApp;
