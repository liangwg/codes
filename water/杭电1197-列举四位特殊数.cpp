#include<iostream>
using namespace std;
void judge(int);
int translate(int,int);
int main()
{
	int i;
	for(i=2992;i<=9999;i++)
	   judge(i);
	return 0;
	
}
void judge(int num)  //�ж��������ֱ���10���ƣ�12���ƣ�16���Ʊ�ʾ 
{
	int d,duod,hexa;
	 d=translate(num,10);
	 duod=translate(num,12);
	 hexa=translate(num,16);
	if(d==duod&&d==hexa)
	   cout<<num<<endl;
	return; 
}
int translate(int num,int x)   //��num��x���ƽ��зֽ⣬�ٽ�ÿ��λ���������� 
{
	int sum=0;
	while(num>=x)
	{ sum+=num%x;
	num=num/x; 
	} 
	return sum+num;
}
