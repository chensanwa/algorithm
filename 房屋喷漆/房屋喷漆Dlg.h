
// ��������Dlg.h : ͷ�ļ�
//

#pragma once


// C��������Dlg �Ի���
class C��������Dlg : public CDialogEx
{
// ����
public:
	C��������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

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

	CDC *picDC;	//ͼƬ�ؼ�DC���豸������
	int picClient_W;	//��ȣ�ͼƬ�ؼ��ͻ���������ͼ�Ρ����֡�ͼ��
	int picClient_H;	//�߶ȣ�ͼƬ�ؼ��ͻ���
	int CenterX,CenterY;	//ͼƬ�ؼ��Ŀͻ�������
	Graphics *graph;	//ͼ�ζ���ָ��
	Color BkColor;	//ͼƬ�ؼ��ͻ�������ɫ����������ͻ�������)
	Bitmap *src;	//ԭͼ��Bitmap������λͼ
	Bitmap *dest;	//���ͼ����ʾ��
	int w,h;	//���ͼ��dest�Ŀ�͸�
	BYTE *R_val;	//ͼ���ɫ����ֵָ�루new���䣩
	BYTE *G_val;	//ͼ����ɫ����ֵָ�룬
	BYTE *B_val;	//ͼ����ɫ����ֵָ��	

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void Onstep1();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32780();
};

#include "ProblemDlg.h"
