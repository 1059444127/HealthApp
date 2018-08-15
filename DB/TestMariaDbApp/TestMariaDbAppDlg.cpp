
// TestMariaDbAppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestMariaDbApp.h"
#include "TestMariaDbAppDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestMariaDbAppDlg �Ի���




CTestMariaDbAppDlg::CTestMariaDbAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMariaDbAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMariaDbAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestMariaDbAppDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CTestMariaDbAppDlg::OnBnConnect)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestMariaDbAppDlg::OnBnQuery)
END_MESSAGE_MAP()


// CTestMariaDbAppDlg ��Ϣ�������

BOOL CTestMariaDbAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestMariaDbAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestMariaDbAppDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestMariaDbAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestMariaDbAppDlg::OnBnConnect()
{
	try
	{	
		//theApp._pDataBase = new DataBase<MySqlDB>("127.0.0.1", "root", "root", "HIT");
		pMariaDb = new HMariaDb("127.0.0.1", "root", "root", "HIT");

// 		GetDlgItem(IDC_BUTTON_CONN)->EnableWindow(false);
// 		GetDlgItem(IDC_BUTTON_CONN)->SetWindowText("connected");
// 		GetDlgItem(IDC_BUTTON_TEST)->EnableWindow(true);
	}
	catch (const DataBaseError& e)
	{
		//MessageBox(e.what());
	}
}

void CTestMariaDbAppDlg::OnBnQuery()
{
	try
	{	
		ResultSet rs;
		std::vector<std::string> row;
		std::string sdata;

		//(*theApp._pDataBase)  << "SELECT * FROM H_istudy", rs;
		std::string strsql = "SELECT * FROM H_istudy";
		pMariaDb->query(strsql);
		pMariaDb->getresult(rs);

		while(rs.fetch(row))
		{
			for (size_t i = 0; i < row.size(); i++)
			{
				sdata += row[i] + " | ";
			}
		}

		//MessageBox(sdata.c);
	}
	catch (const DataBaseError& e)
	{
		//MessageBox(e.what());
	}
}
