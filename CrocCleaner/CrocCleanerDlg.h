
//CrocCleanerDlg.h : header file
//

#pragma once

#include "FileDeleter.h"
#include "FilesListDlg.h"
#include<functional>

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
	int iFileCounter;
	int iFileNumber;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	std::vector<std::filesystem::path> files;
	static UINT threadControlFunction(LPVOID pParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtnclean();
	CComboBox cComboBoxSelection;
	CDateTimeCtrl cDtmStartDate;
	CDateTimeCtrl cDtmEndDate;
	CProgressCtrl cpBar;
	FileDeleter FD;
	CButton cCatalogueClear;
	CMFCEditBrowseCtrl m_brwsPath;
	CButton m_btnFilesList;
	afx_msg void OnBnClickedbtnfileslist();
	

};
