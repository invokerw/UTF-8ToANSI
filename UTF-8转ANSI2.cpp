#include "stdafx.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

string UTF8ToANSI(char *szU8)
{
	//预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
    //最后加上'\0'
    wszString[wcsLen] = '\0';

	string szDst;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wszString,-1,NULL,0,NULL,FALSE);
	
	char *psText;
	psText = new char[dwNum];
	WideCharToMultiByte (CP_OEMCP,NULL,wszString,-1,psText,dwNum,NULL,FALSE);
	szDst = psText;
	//cout<<szDst<<endl;
	// 删除临时变量
	delete []psText;
	return szDst;
}
void OnBnClickedButtonU8ToUnicode()
{
    //UTF8 to Unicode
    //由于中文直接复制过来会成乱码，编译器有时会报错，故采用16进制形式
   // char* szU8 = "abcd1234\xe4\xbd\xa0\xe6\x88\x91\xe4\xbb\x96\x00";
	char szU8[48]= "abc鑳滃摜 杩欐槸涓�鎶婃渶闅句笂鐨?3浜嗭紒锛侊紒";
    //预转换，得到所需空间的大小
    int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0);
    //分配空间要给'\0'留个空间，MultiByteToWideChar不会给'\0'空间
    wchar_t* wszString = new wchar_t[wcsLen + 1];
    //转换
    ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen);
    //最后加上'\0'
    wszString[wcsLen] = '\0';

	string szDst;
	DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wszString,-1,NULL,0,NULL,FALSE);
	
	char *psText;
	psText = new char[dwNum];
	WideCharToMultiByte (CP_OEMCP,NULL,wszString,-1,psText,dwNum,NULL,FALSE);
	szDst = psText;
	cout<<szDst<<endl;
	// 删除临时变量
	delete []psText;

	//// 输出
	//cout << szDst << endl;
 //    //和上面一样有另一种方法
 //   setlocale(LC_CTYPE, "chs"); 
 //   char szStr[100];
 //   //注意下面是大写，在ansi中，代表后面是unicode字符串
 //   //sprintf
 //   sprintf_s(szStr, "%S", wszString);
	//cout<<szStr<<endl;

}
int main()
{
	OnBnClickedButtonU8ToUnicode();
	system("pause");
}
