#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int T,a,b;
	
	char ch;
	cin>>T;
	while(T>=1)
	{
		//程序主要过程
		cin>>ch;cin>>a;cin>>b;
		if(ch=='+')
		{
			cout<< a+b<<endl;
		}
		if(ch=='-')
		   cout<<a-b<<endl;
		if(ch=='*')
		    cout<<a*b<<endl;
		if(ch=='/')
		    {
		    	if(a%b!=0)    //注意这里，当不能整除时，才执行这个 
				{
		    	float result=(float)a/b;
		    	cout<<fixed<<setprecision(2)<<result<<endl;
		         }
		         else
		         {
		         	cout<<a/b<<endl;
				 }
			}
		T--; 
		
	}
	
 } 
