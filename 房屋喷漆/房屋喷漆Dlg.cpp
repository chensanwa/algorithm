
// ��������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������.h"
#include "��������Dlg.h"
#include "afxdialogex.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif


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


// C��������Dlg �Ի���




C��������Dlg::C��������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��������Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C��������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��������Dlg::OnBnClickedButton1)
	ON_COMMAND(ID_32777, &C��������Dlg::On32777)
	ON_COMMAND(ID_32778, &C��������Dlg::On32778)
	ON_COMMAND(ID_step1, &C��������Dlg::Onstep1)
	ON_COMMAND(ID_32772, &C��������Dlg::On32772)
	ON_COMMAND(ID_32773, &C��������Dlg::On32773)
	ON_COMMAND(ID_32774, &C��������Dlg::On32774)
	ON_COMMAND(ID_32775, &C��������Dlg::On32775)
	ON_COMMAND(ID_32776, &C��������Dlg::On32776)
	ON_COMMAND(ID_32780, &C��������Dlg::On32780)
END_MESSAGE_MAP()


// C��������Dlg ��Ϣ�������

BOOL C��������Dlg::OnInitDialog()
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
	picDC=GetDlgItem(IDC_Pic)->GetDC();	//���ͼƬ�ؼ���DC
	CRect rect;
	GetDlgItem(IDC_Pic)->GetClientRect(&rect);	//���ͼƬ�ؼ��ͻ�����С
	picClient_W=rect.Width();
	picClient_H=rect.Height();
	CenterX=rect.CenterPoint().x;
	CenterY=rect.CenterPoint().y;
	//graph=new Graphics(picDC->m_hDC);	//����ͼ�ζ��󣬴�ҹ���
	graph=Graphics::FromHDC(picDC->m_hDC);
	int ColorVal=GetSysColor(COLOR_BTNFACE);	//��ɫֵint 
	char red=GetRValue(ColorVal);	//�����ɫ��R����ֵ
	char green=GetGValue(ColorVal);
	BYTE blue=GetBValue(ColorVal);
	int alpha=255;	//��͸����0ȫ͸��
	BkColor=Color(red,green,blue);		//��ɫ����͸���ȿ���



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��������Dlg::OnPaint()
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
HCURSOR C��������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��������Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void C��������Dlg::On32777()
{
	// TODO: �ڴ���������������
	ProblemDlg problemDlg;
	problemDlg.DoModal();
}


void C��������Dlg::On32778()
{
	// TODO: �ڴ���������������
	//�������
	graph->Clear(BkColor);
	Pen myPen(Color::Black,1);
	Rect rect(120,10,400,400);
	graph->DrawRectangle(&myPen,rect);
	Sleep(100);

	//���Ƹ�����
	/*Point point[]={
	};*/
	for(int i=120;i<=520;i+=50)
	{
		graph->DrawLine(&myPen,Point(i,10),Point(i,410));
		Sleep(100);
	}
	for(int i=10;i<=410;i+=50)
	{
		graph->DrawLine(&myPen,Point(120,i),Point(520,i));
		Sleep(100);
	}
}


void C��������Dlg::Onstep1()
{
	// TODO: �ڴ���������������
	int alpha=255;
	Pen myPen=(Color::Red);	//�ʶ���
	////��
	//for(int i=85;i<=385;i+=50)
	//	graph->DrawLine(&myPen,Point(60+i,i),Point(60+i,i+50));
	////��
	//for(int i=95;i<=445;i+=50)
	//	graph->DrawLine(&myPen,Point(i,i-10),Point(i+50,i-10));

	for(int k=95;k<=445;k+=50)
	{
		graph->DrawLine(&myPen,Point(k,k-10),Point(k+50,k-10));
		Sleep(100);
		graph->DrawLine(&myPen,Point(50+k,k-10),Point(50+k,k+40));
		Sleep(100);
	}
}


void C��������Dlg::On32772()
{
	// TODO: �ڴ���������������
	int alpha=255;
	Pen myPen=(Color::Blue);	//�ʶ���
	for(int k=95;k<=395;k+=50)
	{
		//��
		graph->DrawLine(&myPen,Point(k,k+40),Point(k+50,k+40));
		Sleep(100);
		//��
		graph->DrawLine(&myPen,Point(50+k,k+40),Point(50+k,k+90));
		Sleep(100);
	}
}


void C��������Dlg::On32773()
{
	// TODO: �ڴ���������������
	Pen myPen=(Color::Green);	//�ʶ���
	graph->DrawLine(&myPen,Point(95,280),Point(145,280));
	Sleep(500);
	graph->DrawLine(&myPen,Point(95,290),Point(145,280));
}


void C��������Dlg::On32774()
{
	// TODO: �ڴ���������������
	Pen myPen=(Color::Green);	//�ʶ���
	graph->DrawLine(&myPen,Point(140,380),Point(140,430));
	Sleep(500);
	graph->DrawLine(&myPen,Point(140,380),Point(150,430));
}


void C��������Dlg::On32775()
{
	// TODO: �ڴ���������������
	Pen myPen=(Color::Green);	//�ʶ���
	graph->DrawLine(&myPen,Point(190,420),Point(190,370));
	Sleep(500);
	graph->DrawLine(&myPen,Point(190,370),Point(190,320));
	Sleep(500);
	graph->DrawLine(&myPen,Point(190,320),Point(195,370));
	Sleep(500);
	graph->DrawLine(&myPen,Point(195,370),Point(200,420));
}


void C��������Dlg::On32776()
{
	// TODO: �ڴ���������������
	Pen myPen=(Color::Green);	//�ʶ���
	graph->DrawLine(&myPen,Point(240,380),Point(240,430));
	Sleep(500);
	graph->DrawLine(&myPen,Point(240,380),Point(250,430));
}


void C��������Dlg::On32780()
{
	// TODO: �ڴ���������������
	//��һ��
	int alpha=255;
	Pen myPen1=(Color::Red);	//�ʶ���
	for(int k=95;k<=445;k+=50)
	{
		graph->DrawLine(&myPen1,Point(k,k-10),Point(k+50,k-10));
		Sleep(100);
		graph->DrawLine(&myPen1,Point(50+k,k-10),Point(50+k,k+40));
		Sleep(100);
	}
	Sleep(1000);
	//�ڶ���
	Pen myPen2=(Color::Blue);	//�ʶ���
	for(int k=95;k<=395;k+=50)
	{
		//��
		graph->DrawLine(&myPen2,Point(k,k+40),Point(k+50,k+40));
		Sleep(200);
		//��
		graph->DrawLine(&myPen2,Point(50+k,k+40),Point(50+k,k+90));
		Sleep(200);
	}
	Sleep(1000);
	//������
	Pen myPen=(Color::Green);	//�ʶ���
	graph->DrawLine(&myPen,Point(95,280),Point(145,280));
	Sleep(500);
	graph->DrawLine(&myPen,Point(95,290),Point(145,280));
	Sleep(1000);
	//���Ĳ�
	graph->DrawLine(&myPen,Point(140,380),Point(140,430));
	Sleep(500);
	graph->DrawLine(&myPen,Point(140,380),Point(150,430));
	Sleep(1000);
	//���岽
	graph->DrawLine(&myPen,Point(190,420),Point(190,370));
	Sleep(500);
	graph->DrawLine(&myPen,Point(190,370),Point(190,320));
	Sleep(500);
	graph->DrawLine(&myPen,Point(190,320),Point(195,370));
	Sleep(500);
	graph->DrawLine(&myPen,Point(195,370),Point(200,420));
	Sleep(1000);
	//������
	graph->DrawLine(&myPen,Point(240,380),Point(240,430));
	Sleep(500);
	graph->DrawLine(&myPen,Point(240,380),Point(250,430));
}
