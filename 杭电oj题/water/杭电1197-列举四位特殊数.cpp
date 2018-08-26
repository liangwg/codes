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
void judge(int num)  //判断条件，分别用10进制，12进制，16进制表示 
{
	int d,duod,hexa;
	 d=translate(num,10);
	 duod=translate(num,12);
	 hexa=translate(num,16);
	if(d==duod&&d==hexa)
	   cout<<num<<endl;
	return; 
}
int translate(int num,int x)   //将num按x进制进行分解，再将每个位加起来返回 
{
	int sum=0;
	while(num>=x)
	{ sum+=num%x;
	num=num/x; 
	} 
	return sum+num;
}
