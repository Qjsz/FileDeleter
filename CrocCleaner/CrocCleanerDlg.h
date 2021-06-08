
//CrocCleanerDlg.h : header file
//

#pragma once

#include "FileDeleter.h"

// CCrocCleanerDlg dialog
class CCrocCleanerDlg : public CDialogEx
{
// Construction
public:
	CCrocCleanerDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CROCCLEANER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnclean();
	//CMFCEditBrowseCtrl cBrowssePath;
	CFolderPickerDialog cBrowsePath;
	CComboBox cComboBoxSelection;
	CDateTimeCtrl cDtmStartDate;
	CDateTimeCtrl cDtmEndDate;
	CProgressCtrl cpBar;
	FileDeleter fileDeleter;
	CButton cCatalogueClear;
	CEdit m_txtDateTestStart;
};
