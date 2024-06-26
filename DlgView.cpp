// DlgView.cpp : implementation of the DlgView class
//

#include "stdafx.h"
#include "v9.h"

#include "Doc.h"
#include "DlgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgView

IMPLEMENT_DYNCREATE(DlgView, CFormView)

BEGIN_MESSAGE_MAP(DlgView, CFormView)
	//{{AFX_MSG_MAP(DlgView)
	//}}AFX_MSG_MAP
	ON_EN_KILLFOCUS(IDC_EDIT1, &DlgView::OnEnKillfocusEdit)
	ON_EN_KILLFOCUS(IDC_EDIT2, &DlgView::OnEnKillfocusEdit)
	ON_EN_KILLFOCUS(IDC_EDIT3, &DlgView::OnEnKillfocusEdit)
	ON_EN_KILLFOCUS(IDC_EDIT4, &DlgView::OnEnKillfocusEdit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgView construction/destruction

DlgView::DlgView()
	: CFormView(DlgView::IDD)
{
}

DlgView::~DlgView()
{
}

void DlgView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgView)
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT1, GetDocument()->rect.left);
	DDV_MinMaxInt(pDX, GetDocument()->rect.left, 0, (std::numeric_limits<int>::max)());
	DDX_Text(pDX, IDC_EDIT2, GetDocument()->rect.top);
	DDV_MinMaxInt(pDX, GetDocument()->rect.top, 0, (std::numeric_limits<int>::max)());
	DDX_Text(pDX, IDC_EDIT3, GetDocument()->rect.right);
	DDV_MinMaxInt(pDX, GetDocument()->rect.right, 0, (std::numeric_limits<int>::max)());
	DDX_Text(pDX, IDC_EDIT4, GetDocument()->rect.bottom);
	DDV_MinMaxInt(pDX, GetDocument()->rect.bottom, 0, (std::numeric_limits<int>::max)());
}

BOOL DlgView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFormView::PreCreateWindow(cs);
}

void DlgView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
}

/////////////////////////////////////////////////////////////////////////////
// DlgView diagnostics

#ifdef _DEBUG
void DlgView::AssertValid() const
{
	CFormView::AssertValid();
}

void DlgView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Doc* DlgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Doc)));
	return (Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// DlgView message handlers

void DlgView::OnEnKillfocusEdit()
{
	UpdateData(TRUE);
	GetDocument()->UpdateAllViews(this, 0, 0);
}

void DlgView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	UpdateData(FALSE);
}