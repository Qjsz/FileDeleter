
// CrocCleaner.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCrocCleanerApp:
// See CrocCleaner.cpp for the implementation of this class
//

class CCrocCleanerApp : public CWinApp
{
public:
	CCrocCleanerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCrocCleanerApp theApp;
