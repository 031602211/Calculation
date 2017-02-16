/*************************************************************
文件名：verify.cpp
作者：盖嘉轩 日期：2016/02/16
描述: 检验和输出结果 
主要功能包括：判重、检验答案、输出答案 
*************************************************************/

#include"head.h"

int correct=0,wrong=0;
int ifOnly(string str,string se[],int k) //判断表达式是否重复 
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
void checkAndOutput(string equ,int n,int opt) //检验答案并输出正确答案 
{
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
void finalOut(int opt) //输出正误个数 
{
	cout<<"********************************************************************"<<endl;
	cout<<"                                                                    "<<endl;
	if(opt==2) cout<<"  "<<correct<<" answers are correct, "<<wrong<<" answers are wrong.";
	else cout<<"做对了"<<correct<<"道题，做错了"<<wrong<<"道题";	
}
