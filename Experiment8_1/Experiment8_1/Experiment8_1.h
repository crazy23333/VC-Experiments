
// Experiment8_1.h : Experiment8_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment8_1App:
// �йش����ʵ�֣������ Experiment8_1.cpp
//

class CExperiment8_1App : public CWinApp
{
public:
	CExperiment8_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment8_1App theApp;
