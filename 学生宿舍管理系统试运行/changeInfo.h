#pragma once


// changeInfo 对话框

class changeInfo : public CDialogEx
{
	DECLARE_DYNAMIC(changeInfo)

public:
	changeInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~changeInfo();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strBednum;
	CString m_strBuildingnum;
	CString m_strHouseTel;
	CString m_strId;
	CString m_strMajor;
	CString m_strRemarks;
	CString m_strRoomtype;
	CString m_strStudentname;
	bool m_bMale;
	afx_msg void OnBnClickedMale();
	afx_msg void OnBnClickedFemale();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
