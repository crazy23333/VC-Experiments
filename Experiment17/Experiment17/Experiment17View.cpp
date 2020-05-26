
// Experiment17View.cpp : CExperiment17View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CExperiment17View 构造/析构

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
	// TODO: 在此处添加构造代码
	

}

CExperiment17View::~CExperiment17View()
{
}

void CExperiment17View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CExperiment17View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_Experiment17Set;
	
	CRecordView::OnInitialUpdate();

	combo.AddString(_T("学号"));
	combo.AddString(_T("姓名"));
	combo.AddString(_T("性别"));
	combo.AddString(_T("生日"));
	combo.AddString(_T("专业"));
	combo.AddString(_T("电话"));
	combo.AddString(_T("邮箱"));
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);

}


// CExperiment17View 诊断

#ifdef _DEBUG
void CExperiment17View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CExperiment17View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CExperiment17Doc* CExperiment17View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment17Doc)));
	return (CExperiment17Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment17View 数据库支持
CRecordset* CExperiment17View::OnGetRecordset()
{
	return m_pSet;
}



// CExperiment17View 消息处理程序

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
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
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
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF()) {
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF()) {
		m_pSet->MoveLast();
	}
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	OnPaint();
}


void CExperiment17View::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlg dlg;
	CString s = m_pSet->column8;
	dlg.filename = s;
	dlg.DoModal();
}


void CExperiment17View::OnAdddata()
{
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
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
	// TODO: 在此添加命令处理程序代码
	int choice = MessageBox(_T("是否确认删除该学生的信息？"), _T("注意"), MB_OKCANCEL | MB_ICONWARNING);
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


void CExperiment17View::OnBnClickedButton1()//修改确认
{
	// TODO: 在此添加控件通知处理程序代码
	int choice = MessageBox(_T("是否确认修改该学生的信息？"),_T( "注意"), MB_OKCANCEL | MB_ICONQUESTION);
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


void CExperiment17View::OnBnClickedButton2()//取消
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CString s;
	set = false;
	GetDlgItem(IDC_EDIT6)->GetWindowTextW(s);
	int choice = MessageBox(_T("新增学生")+s+_T("的信息"), _T("注意"), MB_OKCANCEL | MB_ICONQUESTION);
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


void CExperiment17View::OnBnClickedButton8()//恢复
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->m_strFilter = _T("");
	m_pSet->Requery();
}


void CExperiment17View::OnBnClickedButton6()//查询
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	inquire.TrimLeft();
	if (inquire.IsEmpty()) {
		MessageBox(_T("查询不能为空"));
		return;
	}
	if (m_pSet->IsOpen())
		m_pSet->Close();
	m_pSet->m_strFilter.Format(inquire);
	m_pSet->Open();
	if (!m_pSet->IsEOF())
		UpdateData(false);
	else
		MessageBox(_T("无此记录"));
	Invalidate();
	m_pSet->Requery();

}


void CExperiment17View::OnBnClickedButton9()//记录集
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CString str;
	GetDlgItem(IDC_COMBO1)->GetWindowText(str);
	if (str.IsEmpty()) {
		MessageBox(_T("选择不能为空"));
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
