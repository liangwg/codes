#include<iostream>
using namespace std;
int main()
{
	//已知两个整数的和与差，求这两个数 
	int T,x,y,sum,dif;
	cin>>T;
	while(T>=1)
	{
		//主体过程
		cin>>sum;
		cin>>dif;
		if((sum+dif)%2==0&&(sum>=dif)&&(sum-dif)%2==0)  //判断是否符合要求 
		{
			x=(sum+dif)/2;
			y=(sum-dif)/2;
			cout<<x<<" "<<y<<endl; 
		 } 
		 else
		 {
		 	cout<<"impossible\n";
		 }
		T--;
	}
	 
 } 
