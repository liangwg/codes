/*解题思路：数学归纳法    f(x)=5*x^13+13*x^5+k*a*x 
假设当x=n时 65|f(x)成立，那一定有 65|f(n+1)成立 
那么65|f(n+1)-f(n) 成立   通过二项展开可以得到只要18+k*a可以被65整除就可以了 
在0~64之间遍历就ok。
*/
#include<stdio.h>
int main()
{
	int a,k,i,sum,flag=0;
	while(scanf("%d",&k)!=EOF)
	{
		flag=0;
		for(a=0;a<=64;a++)
		{
			sum=18+k*a;
			if(sum%65==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("%d\n",a);
		}
		else
		 printf("no\n");
	}
}
