
// Draw_CruveDlg.h : 头文件
//

#pragma once
#include "ChartCtrl/ChartCtrl.h"
//#include "f:\test\draw_cruve\draw_cruve\chartctrl\chartctrl.h"
#include "ChartCtrl\ChartTitle.h"
#include "ChartCtrl\ChartLineSerie.h"
// CDraw_CruveDlg 对话框
class CDraw_CruveDlg : public CDialogEx
{
// 构造
public:
	CDraw_CruveDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DRAW_CRUVE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CChartCtrl m_ChartCtrl1;
	afx_msg void OnBnClickedDraw();
};
