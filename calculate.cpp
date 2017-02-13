#include"head.h"
int flag=1,k=0;
int getRand(int down,int up)//生成随机数 
{
	if (flag==1)
	{
		flag=0;
		srand((unsigned)time(NULL));//种子 
    }
    return random(down,up);
}
int ifOnly(string str,string se[])
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
string equation[MAX];
void getAndCalculate(int num,int low,int high,char flag1,char flag2,char flag3)
{
	int i=1,para1,para2,right=0,wrong=0,tmp;
	char sign;
	while (i<=num)
	{
		int flag4=1,number=getRand(2,7);
		string paras1,paras2,equ,ans;
		for (int j=0;j<number;j++)
		{
			if (flag1=='y') //允许乘除 
			{
				tmp=getRand(1,4);
				switch (tmp)
				{
					case 1:sign='+';
					       break;
					case 2:sign='-';
					       break;
					case 3:sign='*';
					       break;
					case 4:sign='/';
					       break;
				}
			}
			else
			{
				tmp=getRand(1,2);
				switch (tmp)
				{
					case 1:sign='+';
					       break;
					case 2:sign='-';
					       break;
				}
			}
			if (flag2=='y') //允许分数 
			{
				tmp=getRand(1,3);
				switch (tmp)
				{
					case 1: //整数和整数 
					{
    				    stringstream tmps1,tmps2;
        				para1=getRand(low,high);
     	    			tmps1<<para1;
	        			tmps1>>paras1;
		        		para2=getRand(low,high);
		        		tmps2<<para2;
			        	tmps2>>paras2;
		  				break;
				    }
					case 2: //整数和真分数 
					{
						stringstream tmps;
						para1=getRand(low,high);
						tmps<<para1;
						tmps>>paras1;
						Fraction frac2=simplifyFrac(getFrac(low,high));
						paras2="("+frac2.numerators+"\\"+frac2.denominators+")";
						break;
					}
					case 3: //分数和分数 
					{
						Fraction frac1=simplifyFrac(getFrac(low,high));
						Fraction frac2=simplifyFrac(getFrac(low,high));
						paras1="("+frac1.numerators+"\\"+frac1.denominators+")";
						paras2="("+frac2.numerators+"\\"+frac2.denominators+")";
						break;
					}
				}
			}
			else
			{
				stringstream tmps3,tmps4;
				para1=getRand(low,high);
				tmps3<<para1;
				tmps3>>paras1;
				para2=getRand(low,high);
				tmps4<<para2;
				tmps4>>paras2;
			}
			if (flag3=='y') //允许括号
			{
				tmp=getRand(1,4);
				switch (tmp)
				{
					case 1:
					{
						if (flag4==1)
						{
							equ=paras1+sign+paras2;
							flag4=0;
						}
						else equ=equ+sign+paras1;
					    break;
					}
					case 2:
					{
						if (flag4==1)
						{
							equ=paras2+sign+paras1;
							flag4=0;
						}
						else equ=paras1+sign+equ;
					    break;
					}
					case 3:
					{
						if (flag4==1)
						{
							equ="["+paras1+sign+paras2+"]";
							flag4=0;
						}
						else equ="["+equ+sign+paras1+"]";
					    break;
					}
					case 4:
					{
						if (flag4==1)
						{
							equ="["+paras2+sign+paras1+"]";
							flag4=0;
						}
						else equ="["+equ+sign+paras1+"]";
						break;
					}
				}
			}
			else
			{
				tmp=getRand(1,2);
				switch (tmp)
				{
					case 1:
					{
						if (flag4==1)
						{
							equ=paras1+sign+paras2;
							flag4=0;
						}
						else equ=equ+sign+paras1;
					    break;
					}
					case 2:
					{
						if (flag4==1)
						{
							equ=paras2+sign+paras1;
							flag4=0;
						}
						else equ=paras1+sign+equ;
					}
				}
			}
		}
	 
		if (ifOnly(equ,equation)==1)
		{
			Fraction solution=countEquation(equ);
			string result;
			if (solution.denominator==1) result=solution.numerators;
			else result=solution.numerators+"\\"+solution.denominators;
			//{
				//result=solution.numerators;
				k++;
				equation[k]=equ;
				cout<<"("<<i<<") "<<equ<<"=";
				cin>>ans;
				if (ans==result)
				{
					cout<<"正确"<<endl;
					right++;
				}
				else
				{
					cout<<"错误，正确答案为："<<result<<endl;
					wrong++;
				}
				i++;
			//}
		}
	}
	cout<<"********************************************************************"<<endl;
	cout<<"做对了"<<right<<"道题，做错了"<<wrong<<"道题";
}
