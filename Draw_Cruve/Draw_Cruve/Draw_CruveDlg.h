
// Draw_CruveDlg.h : ͷ�ļ�
//

#pragma once
#include "ChartCtrl/ChartCtrl.h"
//#include "f:\test\draw_cruve\draw_cruve\chartctrl\chartctrl.h"
#include "ChartCtrl\ChartTitle.h"
#include "ChartCtrl\ChartLineSerie.h"
// CDraw_CruveDlg �Ի���
class CDraw_CruveDlg : public CDialogEx
{
// ����
public:
	CDraw_CruveDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DRAW_CRUVE_DIALOG };

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
	CChartCtrl m_ChartCtrl1;
	afx_msg void OnBnClickedDraw();
};
