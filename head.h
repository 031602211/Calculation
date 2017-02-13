#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cmath>
#include<ctime>
#include<stack>
#define Min(x,y) (((x)<(y))?(x):(y))
#define Max(x,y) (((x)>(y))?(x):(y))
#define random(a,b) (rand()%(b-a+1)+a)   
#define MAX 1000
using namespace std;
//extern int flag;   /*声明外部变量*/

            /*Calculate.cpp*/ 
int getRand(int down,int up);
int ifOnly(string str,string equation);
void getAndCalculate(int num,int low,int high,char flag1,char flag2,char flag3);

            /*Fraction.cpp*/
struct Fraction
{
	int numerator,denominator;
	string numerators,denominators;
};
int greatestCommonDivisor(int x,int y);
Fraction getFrac(int low,int high);
Fraction transFrac(int up,int down);
Fraction fixUp(Fraction frac);
Fraction simplifyFrac(Fraction frac);
Fraction addFrac(Fraction frac1,Fraction frac2);
Fraction minusFrac(Fraction frac1,Fraction frac2);
Fraction multiplyFrac(Fraction frac1,Fraction frac2);
Fraction divideFrac(Fraction frac1,Fraction frac2);

			/*Stack.cpp*/ 
void transEquation(string infix,char postfix[]);
Fraction countEquation(string infix);
