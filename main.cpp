/*************************************************************
文件名：main.cpp
作者：盖嘉轩 日期：2016/02/16
描述: 初始界面 
主要功能包括：语言切换、功能选择 
*************************************************************/

#include"head.h"

int main()
{
	int i,j,k,num,low,high,opt;
	char flag1,flag2,flag3,tmp;
	
	cout<<"请问要选择哪种语言/Which language you would like to choose?\n";
	cout<<"输入 1 切换中文 ；输入 2 切换英文./input 1 for Chinese ; input 2 for English: ";
	cin>>opt;
	 
	if(opt==1)
	{
		cout<<"请输入题目数(1~1000)：";
		cin>>num;
		
		cout<<"请输入算式中的数字大小的绝对值范围(如：1 100)：";
		cin>>low>>high;
		
		cout<<"是否允许乘除(y/n):";
		cin>>flag1;
		
		cout<<"是否允许分数(y/n)(结果请以假分数的形式输出,例如13\\5):";
		cin>>flag2;
		
		cout<<"是否允许括号(y/n):";
		cin>>flag3;
		
		cout<<"********************************************************************"<<endl;
		cout<<"                                                                    "<<endl;
	}
    if(opt==2)
	{
		cout<<"Please enter a number as the amount of the calculation questions: ";
		cin>>num;
		
		cout<<"Please enter the size range of the numbers'absolute value in the equation.(e.g 1 100): ";
		cin>>low>>high;
		
		cout<<"Would you permit the  multiplication and division as a part of the equation?(y/n): ";
		cin>>flag1;
		
		cout<<"Would you permit the fraction as a part of the equation?(y/n): ";
		cin>>flag2;
		
		cout<<"Would you permit the parenthesis--() as a part of the equation?(y/n): ";
		cin>>flag3;
		
		cout<<"********************************************************************"<<endl;
		cout<<"                                                                    "<<endl;
	}
	getAndCalculate(opt,num,low,high,flag1,flag2,flag3);
	return 0;
}
