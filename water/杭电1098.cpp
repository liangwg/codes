/*����˼·����ѧ���ɷ�    f(x)=5*x^13+13*x^5+k*a*x 
���赱x=nʱ 65|f(x)��������һ���� 65|f(n+1)���� 
��ô65|f(n+1)-f(n) ����   ͨ������չ�����Եõ�ֻҪ18+k*a���Ա�65�����Ϳ����� 
��0~64֮�������ok��
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
