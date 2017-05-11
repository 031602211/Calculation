/*************************************************************
�ļ�����auxiliary_functions.cpp
���ߣ��Ǽ��� ���ڣ�2017/05/09
����: ��������
��Ҫ���ܣ��Ƚϴ�С����ֵ���������Լ����
���£����������ж�д���������������ж�ȡ�ļ�Ŀ¼���ж��롢д�����
*************************************************************/

#include<iostream>
#include<cstring>
#include<sstream>
#include<ctime>
#include<cassert>
#include<atlstr.h>
#include<fstream>
#include "auxiliary_functions.h"
#define RANDOM(a,b) (rand()%(b-a+1)+a) 
using namespace std;
extern UINT g_idValue;

 
int Max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

 
int Min(int x, int y)
{
	if (x > y) return y;
	else return x;
}

 
int GreatestCommonDivisor(int x, int y)
{
	if (y == 0) return x;
	else return GreatestCommonDivisor(y, x%y);
}

bool ifGenerateSeed = false; 
int RandomNumber(int down, int up)
{
	if (!ifGenerateSeed) 
	{
		ifGenerateSeed = true;
		srand((unsigned)time(NULL)); 
	}
	return RANDOM(down, up);
}

 
bool MatchLanguage(char language[])
{
	stringstream sstmp;
	string stmp;
	sstmp << language;
	sstmp >> stmp; 
	sstmp.clear();
	CString languageName; 
	languageName = stmp.c_str(); 
	CString languageList; 
	g_idValue = 0;
	languageList.LoadString(++g_idValue);
	int ntmp = 0;
	while (languageList != "End")
	{
		if (languageList == languageName) 
		{
			ntmp = 1;
			g_idValue *= 1000; 
			break;
		}
		languageList.LoadString(++g_idValue);
	}
	if (ntmp == 0) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

 
int ReadFile(char *fileName)
{
	int problemNumber; 
	fstream istream;
	istream.open(fileName, ios::in);
	istream >> problemNumber;
	istream.close();
	return problemNumber;
}

 
void WriteFile(char *fileName, int idValue)
{
	wfstream wostream;
	CString sentence; 
	sentence.LoadString(idValue);
	wostream.imbue(locale("CHS"));
	wostream.open(fileName, ios::app);
	wostream << (LPCTSTR)sentence;
	wostream.close();
}

 
void PrintFinalResult(char *fileName, int correct, int wrong)
{
	CString sentence; 
	fstream ostream;
	wfstream wostream;

	ostream.open(fileName, ios::app);
	ostream << "********************************************************************" << endl;
	ostream << endl;
	ostream.close();

	WriteFile(fileName, ++g_idValue);

	ostream.open(fileName, ios::app);
	ostream << correct << endl; 
	ostream.close();

	WriteFile(fileName, ++g_idValue);

	ostream.open(fileName, ios::app);
	ostream << wrong << endl; 
	ostream.close();
}