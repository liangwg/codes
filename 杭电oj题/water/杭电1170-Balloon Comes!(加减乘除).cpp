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
		//������Ҫ����
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
		    	if(a%b!=0)    //ע���������������ʱ����ִ����� 
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
