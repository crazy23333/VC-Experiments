
// Experiment8_2.h : Experiment8_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment8_2App:
// �йش����ʵ�֣������ Experiment8_2.cpp
//

class CExperiment8_2App : public CWinApp
{
public:
	CExperiment8_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment8_2App theApp;
