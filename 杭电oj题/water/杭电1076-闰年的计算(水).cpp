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
		while(!judge(temp))   //�ҵ���һ������ 
		    temp++;
		int count=1;
		while(count<Nth)          //����ٷ��ȽϺ�,��Ϊ��4*Nth����Ļ����ԣ�����һ������ÿ����һ����2200�Ͳ������� 
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
