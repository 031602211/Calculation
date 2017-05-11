/*************************************************************
文件名：Expression.cpp
作者：盖嘉轩 日期：2017/05/09
描述: 定义——类：Expression
主要功能：表达式的生成、计算
作者：盖嘉轩 日期：2017/05/10
*************************************************************/
#include"expression.h"
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
using namespace std;

Expression::Expression() { }

char Expression::RandomOperation(char ifMultiplyDivide)
{
	int tmp;
	if (ifMultiplyDivide == 'y') 
	{
		tmp = RandomNumber(1, 4);
		switch (tmp)
		{
		case 1:
		{
			return '+';
			break;
		}
		case 2:
		{
			return '-';
			break;
		}
		case 3:
		{
			return '*';
			break;
		}
		case 4:
		{
			return '/';
			break;
		}
		}
	}
	else 
	{
		tmp = RandomNumber(1, 2);
		switch (tmp)
		{
		case 1:
		{
			return '+';
			break;
		}
		case 2:
		{
			return '-';
			break;
		}
		}
	}
}

 
bool Expression::IsOnly(string expression)
{
	int count = 0;
	for (unsigned i = 0; i < m_expressionUint.size(); i++)
	{
		if (expression != m_expressionUint[i])
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == m_expressionUint.size()) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}


string Expression::GenerateInfixExpression(int low, int high, int parameterNumber, char ifMultiplyDivide, char ifFraction, char ifBracket)
{
	string expression; 
	for (; ;)
	{
		string parameter1, parameter2; 
		bool ifFirst = true; 
		for (int j = 0; j < parameterNumber - 1; j++)
		{
			int ntmp;
			char sign = RandomOperation(ifMultiplyDivide); 

			if (ifFraction == 'y') 
			{
				ntmp = RandomNumber(1, 3);
				switch (ntmp)
				{
				case 1: 
				{
					stringstream sstmp1, sstmp2;
					sstmp1 << RandomNumber(low, high);
					sstmp1 >> parameter1;
					sstmp2 << RandomNumber(low, high);
					sstmp2 >> parameter2;
					sstmp1.clear();
					sstmp2.clear();
					break;
				}
				case 2:  
				{
					stringstream sstmp;
					sstmp << RandomNumber(low, high);
					sstmp >> parameter1;
					sstmp.clear();
					Fraction fraction2;
					fraction2.GetFraction(low, high);
					fraction2.Simplify();
					parameter2 = fraction2.TransferIntoStringNoInt();
					break;
				}
				case 3: 
				{
					Fraction fraction1, fraction2;
					fraction1.GetFraction(low, high);
					fraction1.Simplify();
					fraction2.GetFraction(low, high);
					fraction2.Simplify();
					parameter1 = fraction1.TransferIntoStringNoInt();
					parameter2 = fraction2.TransferIntoStringNoInt();
					break;
				}
				}
			}
			else 
			{
				stringstream sstmp1, sstmp2;
				sstmp1 << RandomNumber(low, high);
				sstmp1 >> parameter1;
				sstmp2 << RandomNumber(low, high);
				sstmp2 >> parameter2;
				sstmp1.clear();
				sstmp2.clear();
			}
			if (ifBracket == 'y') 
			{
				ntmp = RandomNumber(1, 4);
				switch (ntmp)
				{
				case 1: 
				{
					if (ifFirst)
					{
						expression = parameter1 + sign + parameter2;
						ifFirst = false;
					}
					else
					{
						expression = expression + sign + parameter1;
					}
					break;
				}
				case 2: 
				{
					if (ifFirst)
					{
						expression = parameter2 + sign + parameter1;
						ifFirst = false;
					}
					else
					{
						expression = parameter1 + sign + expression;
					}
					break;
				}
				case 3: 
				{
					if (ifFirst)
					{
						expression = "[" + parameter1 + sign + parameter2 + "]";
						ifFirst = false;
					}
					else
					{
						expression = "[" + expression + sign + parameter1 + "]";
					}
					break;
				}
				case 4: 
				{
					if (ifFirst)
					{
						expression = "[" + parameter2 + sign + parameter1 + "]";
						ifFirst = false;
					}
					else
					{
						expression = "[" + expression + sign + parameter1 + "]";
					}
					break;
				}
				}
			}
			else 
			{
				ntmp = RandomNumber(1, 2);
				switch (ntmp)
				{
				case 1:
				{
					if (ifFirst)
					{
						expression = parameter1 + sign + parameter2;
						ifFirst = false;
					}
					else
					{
						expression = expression + sign + parameter1;
					}
					break;
				}
				case 2:
				{
					if (ifFirst)
					{
						expression = parameter2 + sign + parameter1;
						ifFirst = false;
					}
					else
					{
						expression = parameter1 + sign + expression;
					}
				}
				}
			}
		}
		m_infix = expression;
		if ((IsOnly(expression)) && (CalculateResult() != "non_comformance")) 
		{
			m_expressionUint.push_back(expression);
			break;
		}
	}
	return expression;
}

 
void Expression::TransferInfixIntoPostfix()
{
	unsigned i = 0;
	int j = 0;
	stack<char> signStack; 
	while (i < m_infix.size())
	{
		if ((m_infix[i] >= '0') && (m_infix[i] <= '9')) 
		{
			while ((m_infix[i] >= '0') && (m_infix[i] <= '9'))
			{
				m_postfix[j] = m_infix[i];
				i++;
				j++;
			}
			m_postfix[j] = '!'; 
			j++;
		}
		if (m_infix[i] == '(') 
		{
			while (m_infix[i] != ')')  
			{
				m_postfix[j] = m_infix[i];
				i++;
				j++;
			}
			m_postfix[j] = m_infix[i];
			i++;
			j++;
		}
		if ((m_infix[i] == '+') || (m_infix[i] == '-')) 
		{
			while ((!signStack.empty()) && (signStack.top() != '['))
			{
				m_postfix[j] = signStack.top();
				j++;
				signStack.pop();
			}
			signStack.push(m_infix[i]);
		}
		if ((m_infix[i] == '*') || (m_infix[i] == '/'))  
		{
			while ((!signStack.empty()) && (signStack.top() != '[') && ((signStack.top() == '*') || (signStack.top() == '/')))
			{
				m_postfix[j] = signStack.top();
				j++;
				signStack.pop();
			}
			signStack.push(m_infix[i]);
		}
		if (m_infix[i] == '[') 
		{
			signStack.push(m_infix[i]);
		}
		if (m_infix[i] == ']')  
		{
			while (signStack.top() != '[')
			{
				m_postfix[j] = signStack.top();
				j++;
				signStack.pop();
			}
			signStack.pop();
		}
		i++;
	}
	while (!signStack.empty()) 
	{
		m_postfix[j] = signStack.top();
		j++;
		signStack.pop();
	}
	m_postfix[j] = '\0';  
}

 
string Expression::CalculateResult()
{
	int i = 0;
	int point = -1; 
	bool ifDivideZero = false; 
	Fraction numberStack[kMax]; 
	TransferInfixIntoPostfix();
	while ((m_postfix[i] != '\0') && (i<1000))
	{
		if ((m_postfix[i] >= '0') && (m_postfix[i] <= '9')) 
		{
			double k = 0; 
			while ((m_postfix[i] >= '0') && (m_postfix[i] <= '9'))
			{
				k = 10 * k + m_postfix[i] - '0';
				i++;
			}
			point++;
			numberStack[point].TransferIntIntoFraction(k, 1);
		}
		else
			if (m_postfix[i] == '(') 
			{
				double up = 0, down = 0; 
				i++;
				while (m_postfix[i] != '\\')
				{
					up = 10 * up + m_postfix[i] - '0';
					i++;
				}
				i++;
				while (m_postfix[i] != ')')
				{
					down = 10 * down + m_postfix[i] - '0';
					i++;
				}
				point++;
				numberStack[point].TransferIntIntoFraction(up, down);
			}
			else 
			{
				point--;
				switch (m_postfix[i])
				{
				case '+':
				{
					numberStack[point] = numberStack[point] + numberStack[point + 1];
					break;
				}
				case '-':
				{
					numberStack[point] = numberStack[point] - numberStack[point + 1];
					break;
				}
				case '*':
				{
					numberStack[point] = numberStack[point] * numberStack[point + 1];
					break;
				}
				case '/':
				{
					if (numberStack[point + 1].isDivisorZero()) 
					{
						ifDivideZero = true;
					}
					numberStack[point] = numberStack[point] / numberStack[point + 1];
				}
				}
			}
		i++;
	}
	if ((!ifDivideZero) && (numberStack[point].IsInt())) 
	{
		return numberStack[point].TransferIntoString();
	}
	else
	{
		return "non_comformance";
	}
}