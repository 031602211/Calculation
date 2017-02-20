/*************************************************************
文件名：verify.cpp
作者：盖嘉轩 日期：2016/02/16
描述: 检验和输出结果 
主要功能包括：判重、检验答案、输出答案 
*************************************************************/

#include"head.h"

int correct=0,wrong=0;
bool ifOnly(string str,vector<string> se) //判断表达式是否重复 
{
	int count=0;
	for (int i=0;i<se.size();i++)
	{
		if (str!=se[i]) count++;
		else break;
	}
	    if (count==se.size()) return true;
		else return false;
}
void checkAndOutput(string equ,int n,int opt,string result) //检验答案并输出正确答案 
{
	string ans;
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
