#include<iostream>
using namespace std;
int main()
{
	int num=1,lowest=1;
	while(1)
	{
		cin>>num;
		if(num==0)
		{
			break;
		}
		//������봦�����,����˼·������������2ȡ�෨�������۳˱�����2���������ֵ�һ��1ʱ������ѭ����
		lowest=1;
		while(num%2!=1)
		{
		  lowest*=2;
		  num=num/2;	
		 } 
		 cout<<lowest<<endl;
		 
	}
}
