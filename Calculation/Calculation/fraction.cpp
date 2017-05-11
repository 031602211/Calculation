/*************************************************************
文件名：fraction.cpp
作者：盖嘉轩 日期：2017/05/09
描述: 分数类
主要功能：分数的生成、转换和四则运算
作者：盖嘉轩 日期：2017/05/10
*************************************************************/
#include"fraction.h"
#include<iostream>
#include<sstream>
using namespace std;

Fraction::Fraction() { }

 
void Fraction::GetFraction(int l, int h)
{
	int ntmp1 = 0, ntmp2 = 0;
	stringstream sstmp1, sstmp2;
	while (Max(ntmp1, ntmp2) == 0)
	{
		ntmp1 = RandomNumber(l, h);
		ntmp2 = RandomNumber(l, h);
	}
	m_nnumerator = Min(ntmp1, ntmp2);
	m_ndenominator = Max(ntmp1, ntmp2);
	sstmp1 << m_nnumerator;
	sstmp1 >> m_snumerator;
	sstmp2 << m_ndenominator;
	sstmp2 >> m_sdenominator;
}

 
bool Fraction::isDivisorZero()
{
	if (m_nnumerator == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

 
bool Fraction::IsInt()
{
	if (m_ndenominator == 1) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

 
void Fraction::TransferIntIntoFraction(int up, int down)
{
	stringstream sstmp1, sstmp2;
	m_nnumerator = up;
	m_ndenominator = down;
	sstmp1 << m_nnumerator;
	sstmp1 >> m_snumerator;
	sstmp2 << m_ndenominator;
	sstmp2 >> m_sdenominator;
	sstmp1.clear();
	sstmp2.clear();
}

 
void Fraction::Simplify()
{
	int ntmp;
	stringstream sstmp1, sstmp2;
	if (m_ndenominator < 0) 
	{
		m_ndenominator = -m_ndenominator;
		m_nnumerator = -m_nnumerator;
	}
	if (m_nnumerator == 0) 
	{
		m_ndenominator = 1;
	}
	else
	{
		ntmp = GreatestCommonDivisor(abs(m_ndenominator), abs(m_nnumerator));
		m_nnumerator /= ntmp;
		m_ndenominator /= ntmp;
	}
	sstmp1 << m_nnumerator;
	sstmp1 >> m_snumerator;
	sstmp2 << m_ndenominator;
	sstmp2 >> m_sdenominator;
	sstmp1.clear();
	sstmp2.clear();
}

 
string Fraction::TransferIntoStringNoInt()
{
	return "(" + m_snumerator + "\\" + m_sdenominator + ")";
}

 
string Fraction::TransferIntoString()
{
	if (m_ndenominator == 1) 
	{
		return m_snumerator;
	}
	else
	{
		return "(" + m_snumerator + "\\" + m_sdenominator + ")";
	}
}

 
const Fraction operator +(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator + frac1.m_ndenominator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

 
const Fraction operator -(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator - frac1.m_ndenominator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

 
const Fraction operator *(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_nnumerator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_ndenominator;
	answer.Simplify();
	return answer;
}

 
const Fraction operator /(Fraction frac1, Fraction frac2)
{
	Fraction answer;
	answer.m_nnumerator = frac1.m_nnumerator*frac2.m_ndenominator;
	answer.m_ndenominator = frac1.m_ndenominator*frac2.m_nnumerator;
	answer.Simplify();
	return answer;
}