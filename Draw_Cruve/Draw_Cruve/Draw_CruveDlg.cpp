
// Draw_CruveDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Draw_Cruve.h"
#include "Draw_CruveDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDraw_CruveDlg �Ի���




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


// CDraw_CruveDlg ��Ϣ�������

BOOL CDraw_CruveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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
	
	//����
	//TChartString str1;  
	//str1 = _T("IDC_ChartCtrl1 - m_ChartCtrl1");  
	//m_ChartCtrl1.GetTitle()->AddString(str1); 

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDraw_CruveDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDraw_CruveDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDraw_CruveDlg::OnBnClickedDraw()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	m_ChartCtrl1.RemoveAllSeries();//�����  
	pLineSerie1 = m_ChartCtrl1.CreateLineSerie();  
	pLineSerie1->SetSeriesOrdering(poNoOrdering);//����Ϊ����  
	pLineSerie1->AddPoints(x, y,1000);  
	//pLineSerie1->SetName(_T("����IDC_ChartCtrl1�ĵ�һ����"));//SetName�����ý��ں��潲�� 

	m_ChartCtrl1.EnableRefresh(true);  
	delete []x,y;
}
