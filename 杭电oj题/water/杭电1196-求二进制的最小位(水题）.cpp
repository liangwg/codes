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
		//主体代码处理过程,基本思路就是用连续除2取余法，并将累乘变量乘2，余数出现第一个1时，结束循环，
		lowest=1;
		while(num%2!=1)
		{
		  lowest*=2;
		  num=num/2;	
		 } 
		 cout<<lowest<<endl;
		 
	}
}
