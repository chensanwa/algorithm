#pragma once


// ProblemDlg �Ի���

class ProblemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ProblemDlg)

public:
	ProblemDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ProblemDlg();

// �Ի�������
	enum { IDD = IDD_Problem_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};

#include "��������Dlg.h"
