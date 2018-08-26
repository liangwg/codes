#include<stdio.h>
//int f();
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		if (f(n) % 3 == 0)
//		{
//			printf("yes\n");
//		}
//		else
//		{
//			printf("no\n");
//		}
//	}
//}
//int f(int n)
//{
//	if (n == 0)
//		return 7;
//	else if (n == 1)
//		return 11;
//	else
//		return f(n - 1) + f(n - 2);
//}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if((n-2)%4==0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	
 } 
 
 //这题扎心了，一开始用递归做就知道会超时，毕竟n的边缘是100000，
 //果然，找规律才是王道，n-2是4的倍数时，就行了 
