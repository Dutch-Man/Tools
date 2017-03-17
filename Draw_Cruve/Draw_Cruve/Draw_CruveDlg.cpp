
// Draw_CruveDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Draw_Cruve.h"
#include "Draw_CruveDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDraw_CruveDlg 对话框




CDraw_CruveDlg::CDraw_CruveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDraw_CruveDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDraw_CruveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHARTCTRL1, m_ChartCtrl1);
}

BEGIN_MESSAGE_MAP(CDraw_CruveDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DRAW, &CDraw_CruveDlg::OnBnClickedDraw)
END_MESSAGE_MAP()


// CDraw_CruveDlg 消息处理程序

BOOL CDraw_CruveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	/*CRect rect,rectChart;   
	GetDlgItem(IDC_CHARTCTRL1)->GetWindowRect(&rect);  
	ScreenToClient(rect);  
	rectChart = rect;  
	rectChart.top = rect.bottom + 3;  
	rectChart.bottom = rectChart.top + rect.Height();*/

	CChartAxis *pAxis= NULL;   
	pAxis = m_ChartCtrl1.CreateStandardAxis(CChartCtrl::BottomAxis);  
	pAxis->SetAutomatic(true);  
	pAxis = m_ChartCtrl1.CreateStandardAxis(CChartCtrl::LeftAxis);  
	pAxis->SetAutomatic(true);
	
	//标题
	//TChartString str1;  
	//str1 = _T("IDC_ChartCtrl1 - m_ChartCtrl1");  
	//m_ChartCtrl1.GetTitle()->AddString(str1); 

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDraw_CruveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDraw_CruveDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDraw_CruveDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDraw_CruveDlg::OnBnClickedDraw()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ChartCtrl1.EnableRefresh(false); 
	int num = 1000;
	double *x, *y;
	x = new double[num],y = new double[num];
	for (int i=0; i<1000; i++)  
	{  
		x[i] = i;  
		y[i] = (float(i));  
	}
	CChartLineSerie *pLineSerie1;  
	m_ChartCtrl1.RemoveAllSeries();//先清空  
	pLineSerie1 = m_ChartCtrl1.CreateLineSerie();  
	pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
	pLineSerie1->AddPoints(x, y,1000);  
	//pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第一条线"));//SetName的作用将在后面讲到 

	m_ChartCtrl1.EnableRefresh(true);  
	delete []x,y;
}
