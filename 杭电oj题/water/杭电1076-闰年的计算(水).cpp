#include<iostream>
using namespace std;
int judge(int);
int main()
{
	int T;
	cin>>T; 
	while(T>0)
	{
		int cur_year,Nth,temp;
		int i;
		cin>>cur_year;
		cin>>Nth;
		temp=cur_year;
		while(!judge(temp))   //找到第一个润年 
		    temp++;
		int count=1;
		while(count<Nth)          //用穷举法比较好,因为用4*Nth计算的话不对，并不一定就是每四年一闰，如2200就不是闰年 
		{
			temp=temp+4;
			if(judge(temp))
			   count++;
		 } 
		cout<<temp<<endl;
		T--;
	}
	
 } 
 int judge(int year)
 {
 	if((year%4==0&&year%100!=0)||year%400==0)
 	      return 1;
    else
          return 0;
 }
