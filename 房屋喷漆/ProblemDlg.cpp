// ProblemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������.h"
#include "ProblemDlg.h"
#include "afxdialogex.h"


// ProblemDlg �Ի���

IMPLEMENT_DYNAMIC(ProblemDlg, CDialogEx)

ProblemDlg::ProblemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ProblemDlg::IDD, pParent)
{

}

ProblemDlg::~ProblemDlg()
{
}

void ProblemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ProblemDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ProblemDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ProblemDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// ProblemDlg ��Ϣ�������


void ProblemDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	C��������Dlg homePage;
	homePage.DoModal();
}


void ProblemDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}
