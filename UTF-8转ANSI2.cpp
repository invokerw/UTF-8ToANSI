#include "stdafx.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

string UTF8ToANSI(char *szU8)
{
	//Ԥת�����õ�����ռ�Ĵ�С
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
    //����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ�
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //ת��
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
    //������'\0'
    wszString[wcsLen] = '\0';

	string szDst;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wszString,-1,NULL,0,NULL,FALSE);
	
	char *psText;
	psText = new char[dwNum];
	WideCharToMultiByte (CP_OEMCP,NULL,wszString,-1,psText,dwNum,NULL,FALSE);
	szDst = psText;
	//cout<<szDst<<endl;
	// ɾ����ʱ����
	delete []psText;
	return szDst;
}
void OnBnClickedButtonU8ToUnicode()
{
    //UTF8 to Unicode
    //��������ֱ�Ӹ��ƹ���������룬��������ʱ�ᱨ���ʲ���16������ʽ
   // char* szU8 = "abcd1234\xe4\xbd\xa0\xe6\x88\x91\xe4\xbb\x96\x00";
	char szU8[48]= "abc胜哥 这是一把最难上�?3了！！！";
    //Ԥת�����õ�����ռ�Ĵ�С
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
    //����ռ�Ҫ��'\0'�����ռ䣬MultiByteToWideChar�����'\0'�ռ�
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //ת��
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
    //������'\0'
    wszString[wcsLen] = '\0';

	string szDst;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wszString,-1,NULL,0,NULL,FALSE);
	
	char *psText;
	psText = new char[dwNum];
	WideCharToMultiByte (CP_OEMCP,NULL,wszString,-1,psText,dwNum,NULL,FALSE);
	szDst = psText;
	cout<<szDst<<endl;
	// ɾ����ʱ����
	delete []psText;

	//// ���
	//cout << szDst << endl;
 //    //������һ������һ�ַ���
 //   setlocale(LC_CTYPE, "chs"); 
 //   char szStr[100];
 //   //ע�������Ǵ�д����ansi�У����������unicode�ַ���
 //   //sprintf
 //   sprintf_s(szStr, "%S", wszString);
	//cout<<szStr<<endl;

}
int main()
{
	OnBnClickedButtonU8ToUnicode();
	system("pause");
}
