
// Experiment17View.cpp : CExperiment17View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment17.h"
#endif

#include "Experiment17Set.h"
#include "Experiment17Doc.h"
#include "Experiment17View.h"
#include "Dlg.h"
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment17View

IMPLEMENT_DYNCREATE(CExperiment17View, CRecordView)

BEGIN_MESSAGE_MAP(CExperiment17View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CExperiment17View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CExperiment17View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CExperiment17View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CExperiment17View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON3, &CExperiment17View::OnBnClickedButton3)
	ON_COMMAND(ID_AddData, &CExperiment17View::OnAdddata)
	ON_COMMAND(ID_EditData, &CExperiment17View::OnEditdata)
	ON_COMMAND(ID_DeleteData, &CExperiment17View::OnDeletedata)
	ON_BN_CLICKED(IDC_BUTTON1, &CExperiment17View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CExperiment17View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CExperiment17View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CExperiment17View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CExperiment17View::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CExperiment17View::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CExperiment17View::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON7, &CExperiment17View::OnBnClickedButton7)
END_MESSAGE_MAP()

// CExperiment17View ����/����

CExperiment17View::CExperiment17View()
	: CRecordView(IDD_EXPERIMENT17_FORM)
	, id(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, pro(_T(""))
	, phone(_T(""))
	, email(_T(""))
	, inquire(_T(""))
{
	m_pSet = NULL;
	set = false;
	// TODO: �ڴ˴���ӹ������
	

}

CExperiment17View::~CExperiment17View()
{
}

void CExperiment17View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, inquire);
	DDX_Control(pDX, IDC_COMBO1, combo);
	
}

BOOL CExperiment17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CExperiment17View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Experiment17Set;
	
	CRecordView::OnInitialUpdate();

	combo.AddString(_T("ѧ��"));
	combo.AddString(_T("����"));
	combo.AddString(_T("�Ա�"));
	combo.AddString(_T("����"));
	combo.AddString(_T("רҵ"));
	combo.AddString(_T("�绰"));
	combo.AddString(_T("����"));
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);

}


// CExperiment17View ���

#ifdef _DEBUG
void CExperiment17View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CExperiment17View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CExperiment17Doc* CExperiment17View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment17Doc)));
	return (CExperiment17Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment17View ���ݿ�֧��
CRecordset* CExperiment17View::OnGetRecordset()
{
	return m_pSet;
}



// CExperiment17View ��Ϣ�������

void CExperiment17View::foo(CImage& img, int &sx, int& sy, int& w, int& h)
{
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio) {
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}

}

void CExperiment17View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CImage img;
	if (set) {
		img.Destroy();
	}
	else {
	img.Load(m_pSet->column8);
	int sx, sy, w, h;
	foo(img, sx, sy, w, h);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	}

}


void CExperiment17View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDlg dlg;
	CString s = m_pSet->column8;
	dlg.filename = s;
	dlg.DoModal();
}


void CExperiment17View::OnAdddata()
{
	// TODO: �ڴ���������������
	GetDlgItem(IDC_EDIT2)->EnableWindow(true);
	GetDlgItem(IDC_EDIT3)->EnableWindow(true);
	GetDlgItem(IDC_EDIT4)->EnableWindow(true);
	GetDlgItem(IDC_EDIT5)->EnableWindow(true);
	GetDlgItem(IDC_EDIT6)->EnableWindow(true);
	GetDlgItem(IDC_EDIT7)->EnableWindow(true);
	GetDlgItem(IDC_EDIT1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(true);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(true);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(true);
	filepathprev = m_pSet->column8;

	GetDlgItem(IDC_EDIT8)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(false);
	GetDlgItem(IDC_COMBO1)->EnableWindow(false);
	GetDlgItem(IDC_RADIO1)->EnableWindow(false);
	GetDlgItem(IDC_RADIO2)->EnableWindow(false);

	GetDlgItem(IDC_EDIT6)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT7)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT5)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(_T(""));
	
	set = true;
	OnPaint();
	Invalidate();
}


void CExperiment17View::OnEditdata()
{
	// TODO: �ڴ���������������
	GetDlgItem(IDC_EDIT2)->EnableWindow(true);
	GetDlgItem(IDC_EDIT3)->EnableWindow(true);
	GetDlgItem(IDC_EDIT4)->EnableWindow(true);
	GetDlgItem(IDC_EDIT5)->EnableWindow(true);
	GetDlgItem(IDC_EDIT6)->EnableWindow(true);
	GetDlgItem(IDC_EDIT7)->EnableWindow(true);
	GetDlgItem(IDC_EDIT1)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(true);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(true);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(true);
	filepathprev = m_pSet->column8;

	GetDlgItem(IDC_EDIT8)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(false);
	GetDlgItem(IDC_COMBO1)->EnableWindow(false);
	GetDlgItem(IDC_RADIO1)->EnableWindow(false);
	GetDlgItem(IDC_RADIO2)->EnableWindow(false);
}


void CExperiment17View::OnDeletedata()
{
	// TODO: �ڴ���������������
	int choice = MessageBox(_T("�Ƿ�ȷ��ɾ����ѧ������Ϣ��"), _T("ע��"), MB_OKCANCEL | MB_ICONWARNING);
	if (choice == IDOK) {
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	}
	Invalidate();
}


void CExperiment17View::OnBnClickedButton1()//�޸�ȷ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int choice = MessageBox(_T("�Ƿ�ȷ���޸ĸ�ѧ������Ϣ��"),_T( "ע��"), MB_OKCANCEL | MB_ICONQUESTION);
	if (choice==IDOK) {
		m_pSet->Edit();
		GetDlgItem(IDC_EDIT6)->GetWindowTextW(m_pSet->column1);
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(m_pSet->column2);
		GetDlgItem(IDC_EDIT2)->GetWindowTextW(m_pSet->column3);
		GetDlgItem(IDC_EDIT7)->GetWindowTextW(m_pSet->column4);
		GetDlgItem(IDC_EDIT4)->GetWindowTextW(m_pSet->column5);
		GetDlgItem(IDC_EDIT5)->GetWindowTextW(m_pSet->column6);
		GetDlgItem(IDC_EDIT3)->GetWindowTextW(m_pSet->column7);
		m_pSet->column8 = filepath;
		m_pSet->Update();
		GetDlgItem(IDC_EDIT2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT6)->EnableWindow(false);
		GetDlgItem(IDC_EDIT7)->EnableWindow(false);
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(false);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(false);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(false);

		GetDlgItem(IDC_EDIT8)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(true);
		GetDlgItem(IDC_COMBO1)->EnableWindow(true);
		GetDlgItem(IDC_RADIO1)->EnableWindow(true);
		GetDlgItem(IDC_RADIO2)->EnableWindow(true);
	}
}


void CExperiment17View::OnBnClickedButton2()//ȡ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = false;
	GetDlgItem(IDC_EDIT6)->SetWindowTextW(m_pSet->column1);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(m_pSet->column2);
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(m_pSet->column3);
	GetDlgItem(IDC_EDIT7)->SetWindowTextW(m_pSet->column4);
	GetDlgItem(IDC_EDIT4)->SetWindowTextW(m_pSet->column5);
	GetDlgItem(IDC_EDIT5)->SetWindowTextW(m_pSet->column6);
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(m_pSet->column7);
	m_pSet->column8 = filepathprev;
	GetDlgItem(IDC_EDIT2)->EnableWindow(false);
	GetDlgItem(IDC_EDIT3)->EnableWindow(false);
	GetDlgItem(IDC_EDIT4)->EnableWindow(false);
	GetDlgItem(IDC_EDIT5)->EnableWindow(false);
	GetDlgItem(IDC_EDIT6)->EnableWindow(false);
	GetDlgItem(IDC_EDIT7)->EnableWindow(false);
	GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(false);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(false);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(false);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(false);

	GetDlgItem(IDC_EDIT8)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(true);
	GetDlgItem(IDC_COMBO1)->EnableWindow(true);
	GetDlgItem(IDC_RADIO1)->EnableWindow(true);
	GetDlgItem(IDC_RADIO2)->EnableWindow(true);
	Invalidate();
}


void CExperiment17View::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = false;
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		filepath = CString(cfd.GetPathName());
		filepath.Replace(_T("\\"), _T("\\\\"));
		filepathprev = m_pSet->column8;
		m_pSet->column8 = cfd.GetPathName();
		OnPaint();

	}
}


void CExperiment17View::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString s;
	set = false;
	GetDlgItem(IDC_EDIT6)->GetWindowTextW(s);
	int choice = MessageBox(_T("����ѧ��")+s+_T("����Ϣ"), _T("ע��"), MB_OKCANCEL | MB_ICONQUESTION);
	if (choice == IDOK) {
		m_pSet->AddNew();
		GetDlgItem(IDC_EDIT6)->GetWindowTextW(m_pSet->column1);
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(m_pSet->column2);
		GetDlgItem(IDC_EDIT2)->GetWindowTextW(m_pSet->column3);
		GetDlgItem(IDC_EDIT7)->GetWindowTextW(m_pSet->column4);
		GetDlgItem(IDC_EDIT4)->GetWindowTextW(m_pSet->column5);
		GetDlgItem(IDC_EDIT5)->GetWindowTextW(m_pSet->column6);
		GetDlgItem(IDC_EDIT3)->GetWindowTextW(m_pSet->column7);
		m_pSet->column8 = filepath;
		m_pSet->Update();
		GetDlgItem(IDC_EDIT2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT3)->EnableWindow(false);
		GetDlgItem(IDC_EDIT4)->EnableWindow(false);
		GetDlgItem(IDC_EDIT5)->EnableWindow(false);
		GetDlgItem(IDC_EDIT6)->EnableWindow(false);
		GetDlgItem(IDC_EDIT7)->EnableWindow(false);
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		GetDlgItem(IDC_BUTTON2)->ShowWindow(false);
		GetDlgItem(IDC_BUTTON5)->ShowWindow(false);
		GetDlgItem(IDC_BUTTON4)->ShowWindow(false);

		GetDlgItem(IDC_EDIT8)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON6)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(true);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(true);
		GetDlgItem(IDC_COMBO1)->EnableWindow(true);
		GetDlgItem(IDC_RADIO1)->EnableWindow(true);
		GetDlgItem(IDC_RADIO2)->EnableWindow(true);
	}
}


void CExperiment17View::OnBnClickedButton8()//�ָ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
}


void CExperiment17View::OnBnClickedButton6()//��ѯ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	inquire.TrimLeft();
	if (inquire.IsEmpty()) {
		MessageBox(_T("��ѯ����Ϊ��"));
		return;
	}
	if (m_pSet->IsOpen())
		m_pSet->Close();
	m_pSet->m_strFilter.Format(inquire);
	m_pSet->Open();
	if (!m_pSet->IsEOF())
		UpdateData(false);
	else
		MessageBox(_T("�޴˼�¼"));
	Invalidate();
	m_pSet->Requery();

}


void CExperiment17View::OnBnClickedButton9()//��¼��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDlg1 dlg;
	CString str;
	CString s;
	m_pSet->MoveFirst();
	int n = m_pSet->GetODBCFieldCount();
	while (!m_pSet->IsEOF()) {
		s = _T("");
		for (int i = 0; i < n; i++) {
			m_pSet->GetFieldValue((short)i, str);
			s = s + str+_T("\t") ;
		}
		dlg.str.Add(s);
		m_pSet->MoveNext();
	}

	dlg.DoModal();
}


void CExperiment17View::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	CString str;
	GetDlgItem(IDC_COMBO1)->GetWindowText(str);
	if (str.IsEmpty()) {
		MessageBox(_T("ѡ����Ϊ��"));
		return;
	}
	if (m_pSet->IsOpen())
		m_pSet->Close();
	if (IDC_RADIO1)
		m_pSet->m_strSort.Format(str);
	if (IDC_RADIO2)
		m_pSet->m_strSort.Format(str+_T(" DESC"));
	m_pSet->Open();
	if (!m_pSet->IsEOF())
		UpdateData(false);
	Invalidate();
	m_pSet->Requery();
}
