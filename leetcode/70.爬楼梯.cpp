/*
1.��¥����Ҫn�����ﶥ�㣬ÿһ����������1����2�����ж����ַ������ﶥ��
2.n��һ��������
3.ʾ����2	2��(1+1),(2)
		3	3��(1+1+1),(1+2),(2+1)
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
