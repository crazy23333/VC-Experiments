
// Experiment17View.h : CExperiment17View 类的接口
//

#pragma once
#include "afxwin.h"

class CExperiment17Set;

class CExperiment17View : public CRecordView
{
protected: // 仅从序列化创建
	CExperiment17View();
	DECLARE_DYNCREATE(CExperiment17View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_EXPERIMENT17_FORM };
#endif
	CExperiment17Set* m_pSet;

// 特性
public:
	CExperiment17Doc* GetDocument() const;
	CString filepath;
	CString filepathprev;
	bool set;

// 操作
public:
	void foo(CImage& img, int &sx, int& sy, int& w, int& h);

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CExperiment17View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString id;
	CString name;
	CString sex;
	CString birth;
	CString pro;
	CString phone;
	CString email;
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnAdddata();
	afx_msg void OnEditdata();
	afx_msg void OnDeletedata();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton9();
	CString inquire;
	CComboBox combo;
	afx_msg void OnBnClickedButton7();
};

#ifndef _DEBUG  // Experiment17View.cpp 中的调试版本
inline CExperiment17Doc* CExperiment17View::GetDocument() const
   { return reinterpret_cast<CExperiment17Doc*>(m_pDocument); }
#endif

