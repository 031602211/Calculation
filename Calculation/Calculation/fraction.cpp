/*************************************************************
文件名：fraction.cpp
作者：许郁杨 日期：2016/02/16
描述: 分数类
主要功能包括：分数的生成、转换和四则运算
*************************************************************/

#include"head.h"

int Fraction::greatestCommonDivisor(int x, int y) //最大公约数 
{
	if (y == 0) return x;
	else return greatestCommonDivisor(y, x%y);
}
Fraction::Fraction() { }
Fraction Fraction::getFrac(int l, int h) //生成分数 
{
	Fraction frac;
	int tmp1 = 0, tmp2 = 0;
	char tmpc[MAX];
	stringstream tmps5, tmps6;
	while (Max(tmp1, tmp2) == 0) //防止分母为零 
	{
		tmp1 = getRand(l, h);
		tmp2 = getRand(l, h);
	}
	frac.numerator = Min(tmp1, tmp2);
	frac.denominator = Max(tmp1, tmp2);
	tmps5 << frac.numerator;
	tmps5 >> frac.numerators;
	tmps6 << frac.denominator;
	tmps6 >> frac.denominators;
	return frac;
}
bool Fraction::checkZero(Fraction frac) //防止除数为零 
{
	if (frac.numerator == 0) return true;
	else return false;
}
bool Fraction::checkInt(Fraction frac)
{
	if (frac.denominator == 1) return true;
	else return false;
}
Fraction Fraction::transFrac(int up, int down) //整数转换为分数 
{
	Fraction frac;
	stringstream tmps9, tmps10;
	frac.numerator = up;
	frac.denominator = down;
	tmps9 << frac.numerator;
	tmps9 >> frac.numerators;
	tmps10 << frac.denominator;
	tmps10 >> frac.denominators;
	return frac;
}
Fraction Fraction::simplify(Fraction frac) //分数化简 
{
	int tmp;
	char tmpc[MAX];
	stringstream tmps7, tmps8;
	if (frac.denominator<0)
	{
		frac.denominator = -frac.denominator;
		frac.numerator = -frac.numerator;
	}
	if (frac.numerator == 0) frac.denominator = 1;
	else
	{
		tmp = greatestCommonDivisor(abs(frac.denominator), abs(frac.numerator));
		frac.numerator /= tmp;
		frac.denominator /= tmp;
	}
	tmps7 << frac.numerator;
	tmps7 >> frac.numerators;
	tmps8 << frac.denominator;
	tmps8 >> frac.denominators;
	return frac;
}
string Fraction::transString(Fraction frac) //分数转为字符串（不判断整数）
{
	string str;
	str = "(" + frac.numerators + "\\" + frac.denominators + ")";
	return str;
}
string Fraction::transToString(Fraction frac) //分数转为字符串（判断整数）
{
	string str;
	if (frac.denominator == 1) str = frac.numerators;
	else str = "(" + frac.numerators + "\\" + frac.denominators + ")";
	return str;
}
const Fraction operator +(Fraction frac1, Fraction frac2) //加法 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.denominator + frac1.denominator*frac2.numerator;
	answer.denominator = frac1.denominator*frac2.denominator;
	return answer.simplify(answer);
}
const Fraction operator -(Fraction frac1, Fraction frac2) //减法 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.denominator - frac1.denominator*frac2.numerator;
	answer.denominator = frac1.denominator*frac2.denominator;
	return answer.simplify(answer);
}
const Fraction operator *(Fraction frac1, Fraction frac2) //乘法 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.numerator;
	answer.denominator = frac1.denominator*frac2.denominator;
	return answer.simplify(answer);
}
const Fraction operator /(Fraction frac1, Fraction frac2) //除法 
{
	Fraction answer;
	answer.numerator = frac1.numerator*frac2.denominator;
	answer.denominator = frac1.denominator*frac2.numerator;
	return answer.simplify(answer);
}