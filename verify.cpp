#include"head.h"
//#include"fraction.h"
extern int opt;
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
void checkAndOutput(string equ,int n,int opt)
{
	/*Fraction solution=countEquation(equ);
	string result,ans;
	if (solution.denominator==1) result=solution.numerators;
	else result=solution.numerators+"\\"+solution.denominators;*/
	string result=countEquation(equ),ans;
	cout<<"("<<n<<") "<<equ<<"=";
	cin>>ans;
	if (ans==result)
	{
		if(opt==2)cout<<"Correct Answer!"<<endl;
		else cout<<"正确"<<endl;
		correct++;
	}
	else
	{
		if(opt==2)cout<<"Wrong Answer! The correct answer is "<<result<<endl;
		else cout<<"错误，正确答案为："<<result<<endl;
		wrong++;
	}
}
void finalOut(int opt)
{
	cout<<"********************************************************************"<<endl;
	cout<<"                                                                    "<<endl;
	if(opt==2) cout<<"  "<<correct<<" answers are correct, "<<wrong<<" answers are wrong.";
	else cout<<"做对了"<<correct<<"道题，做错了"<<wrong<<"道题";	
}
