
// Experiment17Set.cpp : CExperiment17Set 类的实现
//

#include "stdafx.h"
#include "Experiment17.h"
#include "Experiment17Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment17Set 实现

// 代码生成在 2020年5月25日, 21:18

IMPLEMENT_DYNAMIC(CExperiment17Set, CRecordset)

CExperiment17Set::CExperiment17Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	m_ID = 0;
	column6 = L"";
	column7 = L"";
	column8 = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}

// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CExperiment17Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\x7ba1\x7406;DBQ=D:\\vc-experiments\\\x5b66\x751f\x4fe1\x606f\x7ba1\x7406.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CExperiment17Set::GetDefaultSQL()
{
	return _T("[学生信息管理]");
}

void CExperiment17Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Text(pFX, _T("[学号]"), column2);
	RFX_Text(pFX, _T("[生日]"), column3);
	RFX_Text(pFX, _T("[性别]"), column4);
	RFX_Text(pFX, _T("[电话]"), column5);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[邮箱]"), column6);
	RFX_Text(pFX, _T("[专业]"), column7);
	RFX_Text(pFX, _T("[照片路径]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CExperiment17Set 诊断

#ifdef _DEBUG
void CExperiment17Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CExperiment17Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

