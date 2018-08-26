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
	int max=0x7fffffff;//32bit的最大值 
	int min=0x80000000; //32bit的最小值 
	long sum=0;   //用long 型存储不会超掉
	int seat;
	while(x!=0)
	{
		seat=x%10;
		sum=sum*10+seat;
		//判断条件
		if(sum>max||sum<min)return 0;
			x=x/10; 
	 } 
	 return sum;
}
