#include"head.h"
int greatestCommonDivisor(int x,int y)
{
	if (y==0) return x;
	else return greatestCommonDivisor(y,x%y);
}
int Max(int x,int y)
{
	if (x>y) return x;
	else return y;
}
int Min(int x,int y)
{
	if (x<y) return x;
	else return y;
}
Fraction getFrac(int low,int high)
{
	Fraction frac;
	int tmp1,tmp2;
	char tmpc[MAX];
	stringstream tmps1,tmps2;
	tmp1=getRand(low,high);
	tmp2=getRand(low,high);
	frac.numerator=Min(tmp1,tmp2);
	frac.denominator=Max(tmp1,tmp2);
	tmps1<<frac.numerator;
	tmps1>>frac.numerators;
	tmps2<<frac.denominator;
	tmps2>>frac.denominators;
	return frac;
}
Fraction fixUp(Fraction frac)
{
	if (frac.denominator<0)
	{
		frac.denominator=-frac.denominator;
		frac.numerator=-frac.numerator;
    }
    return frac;
}
Fraction simplifyFrac(Fraction frac)
{
	int tmp;
	char tmpc[MAX];
	stringstream tmps1,tmps2;
	fixUp(frac);
	if (frac.numerator==0) frac.denominator=1;
	else
	{
		tmp=greatestCommonDivisor(fabs(frac.numerator),fabs(frac.denominator));
		frac.numerator/=tmp;
		frac.denominator/=tmp;
	}
	tmps1<<frac.numerator;
	tmps1>>frac.numerators;
	tmps2<<frac.denominator;
	tmps2>>frac.denominators;
	return frac;
}
Fraction addFrac(Fraction frac1,Fraction frac2)
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.denominator+frac1.denominator*frac2.numerator;
	answer.denominator=frac1.denominator*frac2.denominator;
	return simplifyFrac(answer);
}
Fraction minusFrac(Fraction frac1,Fraction frac2)
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.denominator-frac1.denominator*frac2.numerator;
	answer.denominator=frac1.denominator*frac2.denominator;
	return simplifyFrac(answer);
}
Fraction multiplyFrac(Fraction frac1,Fraction frac2)
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.numerator;
	answer.denominator=frac1.denominator*frac2.denominator;
	return simplifyFrac(answer);
}
Fraction divideFrac(Fraction frac1,Fraction frac2)
{
	Fraction answer;
	answer.numerator=frac1.numerator*frac2.denominator;
	answer.denominator=frac1.denominator*frac2.numerator;
	return simplifyFrac(answer);
}
