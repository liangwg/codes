/*
1.爬楼梯需要n步到达顶点，每一次你能迈出1或者2步，有多少种方法到达顶端
2.n是一个正整数
3.示例：2	2种(1+1),(2)
		3	3种(1+1+1),(1+2),(2+1)
-------------------------------------
1.f(n)=f(n-1)+f(n-2),n>=3,f(1)=1,f(2)=2
*/ 
#include<iostream>
using namespace std;
int climbStairs(int n);
int main()
{
	int n;
	cin>>n;
	cout<<climbStairs(n);
	return 0;
	
}
int climbStairs(int n)
{
	int fi1=1,fi2=2,fin;
	if(n==1||n==2)return n;
	int i=3;
	while(i<=n)
	{
		fin=fi1+fi2;
		i++;
		fi1=fi2;
		fi2=fin;
	}
	return fin;
	
}
