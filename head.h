/*************************************************************
文件名：head.h 
作者：盖嘉轩 日期：2016/02/16
描述: 头文件 
*************************************************************/

#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
#include<ctime>
#include<stack>
#include<cassert>
#define Min(x,y) (((x)<(y))?(x):(y))
#define Max(x,y) (((x)>(y))?(x):(y))
#define random(a,b) (rand()%(b-a+1)+a)   
#define MAX 1000
using namespace std;

/*generate.cpp*/ 
int getRand(int down,int up);
void getAndCalculate(int opt,int num,int low,int high,char flag1,char flag2,char flag3);

/*Stack.cpp*/ 
void transEquation(string infix,char postfix[]);
string countEquation(string infix);

/*verify.cpp*/
int ifOnly(string str,string se[],int k);
void checkAndOutput(string equ,int n,int opt);
void finalOut(int opt);

/*fraction.cpp*/
class Fraction
{
	private:
		int numerator,denominator;
		string numerators,denominators;
		int greatestCommonDivisor(int x,int y);
		void fixUp(Fraction frac); 
	
	public:
		Fraction();
		Fraction(int numerator,int denominator);
		Fraction getFrac(int l,int h);
		Fraction transFrac(int up,int down);
		
		Fraction simplify(Fraction frac);
		string transString(Fraction frac);
		string transToString(Fraction frac);
		
		friend const Fraction operator +(Fraction frac1,Fraction frac2);  
        friend const Fraction operator -(Fraction frac1,Fraction frac2);  
        friend const Fraction operator *(Fraction frac1,Fraction frac2);  
        friend const Fraction operator /(Fraction frac1,Fraction frac2); 
};
