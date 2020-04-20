#pragma once


// MyDLg 对话框

class MyDLg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDLg)

public:
	MyDLg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDLg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long a;
	long b;
};
