#include"head.h"
int correct=0,wrong=0;
int ifOnly(string str,string se[],int k)
{
	int count=0;
	for (int i=0;i<k;i++)
	{
		if (str!=se[i]) count++;
		else break;
	}
	    if (count==k) return 1;
		else return 0;
}
void checkAndOutput(string equ,int n)
{
	Fraction solution=countEquation(equ);
	string result,ans;
	if (solution.denominator==1) result=solution.numerators;
	else result=solution.numerators+"\\"+solution.denominators;
	cout<<"("<<n<<") "<<equ<<"=";
	cin>>ans;
	if (ans==result)
	{
		cout<<"正确"<<endl;
		correct++;
	}
	else
	{
		cout<<"错误，正确答案为："<<result<<endl;
		wrong++;
	}
}
void finalOut()
{
	cout<<"********************************************************************"<<endl;
	cout<<"做对了"<<correct<<"道题，做错了"<<wrong<<"道题";
}
