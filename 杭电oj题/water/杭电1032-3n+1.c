#include<stdio.h>
int done(int);
int main()
{
	int start, end, max=0, i, j,temp=0,a,b;
	while (scanf("%d %d", &start, &end) != EOF)
	{
		a=start;  //ע����Ŀ��Ҫ���Ǵ�i��j����û��˵��j��i�Ĵ�С��ϵ������Ҫ������ͬʱ���˳��ȴ���ܱ� 
		b=end;
		max = 0;
		
		if(end<start)
		   {
		   	temp=end;
		   	end=start;
		   	start=temp;
		   }
		for (i = start; i <= end; i++)
		{
			temp = done(i);
			max = (max > temp ? max : temp);
			


		}
		printf("%d %d %d\n", a, b, max);
	}
	return 0;
}
int done(int n)
{
	int sum = 1;
	while (n != 1)
	{
		if (n % 2 != 0)
			n = 3 * n + 1;
		else
			n = n / 2;
		sum++;
	}
	return sum;
}
