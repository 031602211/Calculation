#include"head.h"
//#include"fraction.h"
int main()
{
	int i,j,k,num,low,high;
	char flag1,flag2,flag3,tmp;
	
	cout<<"请输入题目数(1~1000)：";
	cin>>num;
	
	cout<<"请输入算式中的数字大小的绝对值范围(如：1 100)：";
	cin>>low>>high;
	
	cout<<"是否允许乘除(y/n):";
	cin>>flag1;
	//if (tmp=="y") flag1=1;
	//else flag1=0;
	
	cout<<"是否允许分数(y/n)(结果请以假分数的形式输出,例如13\\5):";
	cin>>flag2;
	
	cout<<"是否允许括号(y/n):";
	cin>>flag3;
	
	cout<<"********************************************************************"<<endl;
	
	getAndCalculate(num,low,high,flag1,flag2,flag3);
	return 0;
}
