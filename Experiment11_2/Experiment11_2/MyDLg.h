#pragma once


// MyDLg �Ի���

class MyDLg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDLg)

public:
	MyDLg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDLg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long a;
	long b;
};
