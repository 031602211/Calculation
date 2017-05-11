/*************************************************************
文件名：auxiliary_functions.h
作者：盖嘉轩 日期：2017/05/09
描述: auxiliary_functions.cpp对应头文件
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
