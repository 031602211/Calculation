/*************************************************************
�ļ�����auxiliary_functions.h
���ߣ��Ǽ��� ���ڣ�2017/05/09
����: auxiliary_functions.cpp��Ӧͷ�ļ�
*************************************************************/
#pragma once

int Max(int x, int y);
int Min(int x, int y);
int GreatestCommonDivisor(int x, int y);
int RandomNumber(int down, int up);
bool MatchLanguage(char language[]);
int ReadFile(char *fileName);
void WriteFile(char *fileName, int idValue);
void PrintFinalResult(char *fileName, int correct, int wrong);
