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
 
 //���������ˣ�һ��ʼ�õݹ�����֪���ᳬʱ���Ͼ�n�ı�Ե��100000��
 //��Ȼ���ҹ��ɲ���������n-2��4�ı���ʱ�������� 
