#include"head.h"
//#include"fraction.h"
int main()
{
	int i,j,k,num,low,high;
	char flag1,flag2,flag3,tmp;
	
	cout<<"��������Ŀ��(1~1000)��";
	cin>>num;
	
	cout<<"��������ʽ�е����ִ�С�ľ���ֵ��Χ(�磺1 100)��";
	cin>>low>>high;
	
	cout<<"�Ƿ�����˳�(y/n):";
	cin>>flag1;
	//if (tmp=="y") flag1=1;
	//else flag1=0;
	
	cout<<"�Ƿ��������(y/n)(������Լٷ�������ʽ���,����13\\5):";
	cin>>flag2;
	
	cout<<"�Ƿ���������(y/n):";
	cin>>flag3;
	
	cout<<"********************************************************************"<<endl;
	
	getAndCalculate(num,low,high,flag1,flag2,flag3);
	return 0;
}
