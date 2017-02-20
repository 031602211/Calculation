/*************************************************************
文件名：stack.cpp 
作者：许郁杨 日期：2016/02/16
描述: 栈 
主要功能包括：中缀转换为后缀、计算后缀 
*************************************************************/

#include"head.h"

 //运算符栈 
void transEquation(string infix,char postfix[]) //中缀转为后缀 
{
	int i=0,j=0;stack<char> stored;
	while (i<infix.size())
	//while (infix[i]!='\0')
	{
		if ((infix[i]>='0')&&(infix[i]<='9')) //判断数字 
		{
			while ((infix[i]>='0')&&(infix[i]<='9'))
			{
					postfix[j]=infix[i];
					i++;
					j++;
			}
			postfix[j]='!'; //标识单个整数 
			j++;
		}
		if (infix[i]=='(') //判断分数 
		{	
			while (infix[i]!=')') //将分数作为整体 
    		{
	    		postfix[j]=infix[i];
		    	i++;
    			j++;
    		}
    		postfix[j]=infix[i];
    		i++;
    		j++;
		}
		if ((infix[i]=='+')||(infix[i]=='-')) //判断'+'、'-' 
		{
			while ((!stored.empty())&&(stored.top()!='['))
			{
				postfix[j]=stored.top();
				j++;
				stored.pop();
			}
			stored.push(infix[i]);
		}
		if ((infix[i]=='*')||(infix[i]=='/')) //判断'*'、'/' 
		{
			while ((!stored.empty())&&(stored.top()!='[')&&((stored.top()=='*')||(stored.top()=='/')))
			{
				postfix[j]=stored.top();
				j++;
				stored.pop();
			}
			stored.push(infix[i]);
		}
		if (infix[i]=='[') stored.push(infix[i]); //判断'[' 
		if (infix[i]==']') //判断']' 
		{
			while (stored.top()!='[')
			{
				postfix[j]=stored.top();
				j++;
				stored.pop();
			}
			stored.pop();
		}
		i++;
	}
	while (!stored.empty()) //残余运算符 
	{
		postfix[j]=stored.top();
		j++;
		stored.pop();
	}
	postfix[j]='\0'; //终止符 
}
 //数栈 
string countEquation(string infix) //计算后缀的值 
{
	int i=0,point=-1,check=0;
	char postfix[MAX];Fraction figure[MAX];
	transEquation(infix,postfix);
	while ((postfix[i]!='\0')&&(i<1000))
	{
		if ((postfix[i]>='0')&&(postfix[i]<='9')) //整数入栈 
		{
			double k=0; //int会计算出错 
			while ((postfix[i]>='0')&&(postfix[i]<='9'))
			{
				k=10*k+postfix[i]-'0';
				i++;
			}
			point++;
			figure[point]=figure[point].transFrac(k,1);
    	}
    	else
    	if (postfix[i]=='(') //分数入栈 
    	{
			double up=0,down=0; //int会计算出错 
			i++;
			while (postfix[i]!='\\')
			{
				up=10*up+postfix[i]-'0';
				i++;
			}
			i++;
			while (postfix[i]!=')')
			{
				down=10*down+postfix[i]-'0';
				i++;
			}
			point++;
			figure[point]=figure[point].transFrac(up,down);
		}
		else
		{
			point--;
			switch (postfix[i])
			{
				case '+':figure[point]=figure[point]+figure[point+1];
				         break;
				case '-':figure[point]=figure[point]-figure[point+1];
				         break;
				case '*':figure[point]=figure[point]*figure[point+1];
				         break;
				case '/':if (figure[point+1].checkZero(figure[point+1])) check=1; //标识除零 
					     figure[point]=figure[point]/figure[point+1];
			}
		}
		i++;
	}
	if ((check==0)&&(figure[point].checkInt(figure[point]))) return figure[point].transToString(figure[point]); //判断是否除零 
	else return "non_comformance";
}
