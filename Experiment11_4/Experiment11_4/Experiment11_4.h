
// Experiment11_4.h : Experiment11_4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CExperiment11_4App:
// �йش����ʵ�֣������ Experiment11_4.cpp
//

class CExperiment11_4App : public CWinApp
{
public:
	CExperiment11_4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment11_4App theApp;
