
// Experiment15_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CExperiment15_1Dlg �Ի���
class CExperiment15_1Dlg : public CDialogEx
{
// ����
public:
	CExperiment15_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CExperiment15_1Dlg();
	CString filename;
	int choose;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPERIMENT15_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox namelist;
	afx_msg void OnLbnSelchangeList1();
	CString name;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
};
