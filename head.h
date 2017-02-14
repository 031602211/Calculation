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
void getAndCalculate(int num,int low,int high,char flag1,char flag2,char flag3);

/*Fraction.cpp*/
/*struct Fraction
{
	int numerator,denominator;
	string numerators,denominators;
};
int greatestCommonDivisor(int x,int y);
Fraction getFrac(int low,int high);
Fraction transFrac(int up,int down);
void fixUp(Fraction frac);
Fraction simplifyFrac(Fraction frac);
Fraction addFrac(Fraction frac1,Fraction frac2);
Fraction minusFrac(Fraction frac1,Fraction frac2);
Fraction multiplyFrac(Fraction frac1,Fraction frac2);
Fraction divideFrac(Fraction frac1,Fraction frac2);*/

/*Stack.cpp*/ 
void transEquation(string infix,char postfix[]);
string countEquation(string infix);

/*verify*/
int ifOnly(string str,string se[],int k);
void checkAndOutput(string equ,int n);
void finalOut();

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
