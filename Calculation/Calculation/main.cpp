/*************************************************************
文件名：main.cpp
作者：盖嘉轩 日期：2017/05/09
描述: 主函数
作者：盖嘉轩 日期：2017/05/09
更新：使用命令行输入输出；在文件中输出题目数量和用户答案。
*************************************************************/
#include"expression.h"
#include"auxiliary_functions.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cassert>
#include<atlstr.h>
#include<fstream>
using namespace std;
UINT g_idValue;//

int main(int argc, char *argv[])
{
	wcout.imbue(locale("CHS"));// 
	cout << "Which language you would like to choose?\n";

	int serialNumber = 1;// 
	g_idValue = 0;
	CString languageList;// 
	languageList.LoadString(++g_idValue);// 
	while (languageList != "End")// 
	{
		cout << serialNumber << '.';
		wcout << (LPCTSTR)languageList << endl;
		serialNumber++;
		languageList.LoadString(++g_idValue);
	}
	cout << "Please input the name of the language: ";

	bool isSupportLanguage = false;// 
	g_idValue = 0;
	while (!isSupportLanguage)
	{
		char Language[kMax];// 
		fgets(Language, kMax, stdin);
		isSupportLanguage = MatchLanguage(Language);
		if (!isSupportLanguage)// 
		{
			cout << "Sorry, please choose other language: ";
		}
	}

	int problemNumber;// 
	problemNumber = ReadFile(argv[1]);

	CString sentence;// 
	sentence.LoadString(g_idValue);
	wfstream wostream;
	wostream.imbue(locale("CHS"));
	wostream.open(argv[2], ios::out);
	wostream << (LPCTSTR)sentence << problemNumber << endl << endl << "********************************************************************" << endl << endl;
	wostream.close();

	int low, high;// 
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> low >> high;

	int parameterNumber;// 
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> parameterNumber;

	char ifMultiplyDivide;// 
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifMultiplyDivide;

	char ifFraction;// 
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifFraction;

	char ifBracket;// 
	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence;
	cin >> ifBracket;

	cout << endl << "********************************************************************" << endl;
	cout << endl;

	sentence.LoadString(++g_idValue);
	wcout << (LPCTSTR)sentence << endl << endl;// 

	g_idValue += 2;

	int correct = 0, wrong = 0;// 
	for (int i = 1; i <= problemNumber; i++)
	{
		Expression expression;// 
		string answer;// 
		string result;// 
		string equation;// 

		equation = expression.GenerateInfixExpression(low, high, parameterNumber, ifMultiplyDivide, ifFraction, ifBracket);
		cout << "(" << i << ") " << equation << "=";
		cin >> answer;
		cout << endl;

		fstream ostream;
		wfstream wostream;

		wostream.imbue(locale("CHS"));

		ostream.open(argv[2], ios::app);
		ostream << "(" << i << ") " << equation << endl;
		ostream.close();

		if (answer == "e")// 
		{
			PrintFinalResult(argv[2], correct, wrong);
			exit(0);
		}

		WriteFile(argv[2], g_idValue + 3);

		ostream.open(argv[2], ios::app);
		ostream << answer << endl;
		ostream.close();

		result = expression.CalculateResult();
		if (answer == result)// 
		{
			WriteFile(argv[2], g_idValue - 1);

			correct++;
		}
		else// 
		{
			WriteFile(argv[2], g_idValue);

			ostream.open(argv[2], ios::app);
			ostream << result << endl;
			ostream.close();

			wrong++;
		}
		ostream.open(argv[2], ios::app);
		ostream << endl;
		ostream.close();
	}
	cout << "********************************************************************" << endl;
	PrintFinalResult(argv[2], correct, wrong);// 
	return 0;
}
