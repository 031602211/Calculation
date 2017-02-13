#include"head.h"
stack<char> stored;
void transEquation(string infix,char postfix[])
{
	int i=0,j=0;
	while (infix[i]!='\0')
	{
		if ((infix[i]>='0')&&(infix[i]<='9'))
		{
			while ((infix[i]>='0')&&(infix[i]<='9'))
			{
					postfix[j]=infix[i];
					i++;
					j++;
			}
			postfix[j]='!';
			j++;
		}
		if (infix[i]=='(')
		{	
			while (infix[i]!=')')
    		{
	    		postfix[j]=infix[i];
		    	i++;
    			j++;
    		}
    		postfix[j]=infix[i];
    		i++;
    		j++;
		}
		if ((infix[i]=='+')||(infix[i]=='-'))
		{
			while ((!stored.empty())&&(stored.top()!='['))
			{
				postfix[j]=stored.top();
				j++;
				stored.pop();
			}
			stored.push(infix[i]);
		}
		if ((infix[i]=='*')||(infix[i]=='/'))
		{
			while ((!stored.empty())&&(stored.top()!='[')&&((stored.top()=='*')||(stored.top()=='/')))
			{
				postfix[j]=stored.top();
				j++;
				stored.pop();
			}
			stored.push(infix[i]);
		}
		if (infix[i]=='[') stored.push(infix[i]);
		if (infix[i]==']')
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
	while (!stored.empty())
	{
		postfix[j]=stored.top();
		j++;
		stored.pop();
	}
	postfix[j]='\0';
}
Fraction figure[MAX];
Fraction countEquation(string infix)
{
	int i=0,point=-1;
	char postfix[MAX];
	transEquation(infix,postfix);
	while (postfix[i]!='\0')
	{
		if ((postfix[i]>='0')&&(postfix[i]<='9'))
		{
			double k=0;
			while ((postfix[i]>='0')&&(postfix[i]<='9'))
			{
				k=10*k+postfix[i]-'0';
				i++;
			}
			point++;
			figure[point]=transFrac(k,1);
    	}
    	else
    	if (postfix[i]=='(')
    	{
			double up=0,down=0;
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
			figure[point]=transFrac(up,down);
		}
		else
		{
			point--;
			switch (postfix[i])
			{
				case '+':figure[point]=addFrac(figure[point],figure[point+1]);
				         break;
				case '-':figure[point]=minusFrac(figure[point],figure[point+1]);
				         break;
				case '*':figure[point]=multiplyFrac(figure[point],figure[point+1]);
				         break;
				case '/':figure[point]=divideFrac(figure[point],figure[point+1]);
			}
		}
		i++;
	}
	return figure[point];
}
