
// Experiment15_2Doc.h : CExperiment15_2Doc ��Ľӿ�
//


#pragma once


class CExperiment15_2Doc : public CDocument
{
protected: // �������л�����
	CExperiment15_2Doc();
	DECLARE_DYNCREATE(CExperiment15_2Doc)

// ����
public:

// ����
public:
	CArray<CRect, CRect&> cr;
	CArray<COLORREF, COLORREF&> color;
	int n;

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CExperiment15_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
