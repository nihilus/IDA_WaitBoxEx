
// Subclass of QProgressDialog for customization
#pragma once

#define WIN32_LEAN_AND_MEAN
#define WINVER       _WIN32_WINNT_WINXP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define _WIN32_IE_   _WIN32_WINNT_WINXP
#include <Windows.h>
#include <exception>

#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtGui/QApplication>
#include <QtGui/QProgressDialog>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QProgressBar>

class MyQProgressDialog : public QProgressDialog
{   
    Q_OBJECT
public:
    MyQProgressDialog(LPCSTR titleText, LPCSTR labelText, LPCSTR styleSheet, LPCSTR icon);
    ~MyQProgressDialog();
    BOOL updateAndCancelCheck(int progress);
    BOOL isCanceled() { return(m_isCanceled); }

private:
    void showEvent(QShowEvent *event);

    int    m_lastProgress;    
    BOOL   m_isCanceled, m_indeterminateMode;   
    HHOOK  m_hMouseHook, m_hWinHook;
    HANDLE m_hTimerQueue, m_hUpdateTimer;
};

