
// Experiment17.h : Experiment17 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CExperiment17App:
// 有关此类的实现，请参阅 Experiment17.cpp
//

class CExperiment17App : public CWinApp
{
public:
	CExperiment17App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment17App theApp;
