#include<iostream>
using namespace std;
int Reverse(int);
int main()
{
	int x;
	cin>>x;
	cout<<Reverse(x);
}
int Reverse(int x)
{
	int max=0x7fffffff;//32bit�����ֵ 
	int min=0x80000000; //32bit����Сֵ 
	long sum=0;   //��long �ʹ洢���ᳬ��
	int seat;
	while(x!=0)
	{
		seat=x%10;
		sum=sum*10+seat;
		//�ж�����
		if(sum>max||sum<min)return 0;
			x=x/10; 
	 } 
	 return sum;
}
