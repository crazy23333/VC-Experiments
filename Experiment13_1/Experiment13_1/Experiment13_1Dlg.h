
// Experiment13_1Dlg.h : ͷ�ļ�
//

#pragma once


// CExperiment13_1Dlg �Ի���
class CExperiment13_1Dlg : public CDialogEx
{
// ����
public:
	CExperiment13_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPERIMENT13_1_DIALOG };
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
	double first;
	double second;
	int set;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedSqu();
	afx_msg void OnBnClickedRec();
	afx_msg void OnBnClickedEqual();
	CString result;
};
