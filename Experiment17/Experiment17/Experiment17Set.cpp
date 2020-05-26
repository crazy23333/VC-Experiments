
// Experiment17Set.cpp : CExperiment17Set ���ʵ��
//

#include "stdafx.h"
#include "Experiment17.h"
#include "Experiment17Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment17Set ʵ��

// ���������� 2020��5��25��, 21:18

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

// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CExperiment17Set::GetDefaultConnect()
{
	return _T("DSN=\x5b66\x751f\x4fe1\x606f\x7ba1\x7406;DBQ=D:\\vc-experiments\\\x5b66\x751f\x4fe1\x606f\x7ba1\x7406.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CExperiment17Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ����]");
}

void CExperiment17Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[����]"), column3);
	RFX_Text(pFX, _T("[�Ա�]"), column4);
	RFX_Text(pFX, _T("[�绰]"), column5);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column6);
	RFX_Text(pFX, _T("[רҵ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ·��]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CExperiment17Set ���

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

