#include<stdio.h>
int find_sum(int,int);
int main()
{
	int N, n, m, sum;
	
	scanf("%d", &N);  //测试模块数量
	int temp=N-1;
	int i = 1;
	//printf("\n");
	while (N != 0) {
		N--;
		if(N<temp)
		   printf("\n");  //此题注意格式问题，每个输出块之间都空一行 
		 i = 1;
		scanf("%d%d", &n, &m);
		while (!(n==0 && m==0)) {          //注意 !(n==0 && m==0)与n!=0&&m!=0不一样 
			sum=find_sum(n,m);
			printf("Case %d: %d\n",i,sum);
			i++;

			scanf("%d%d", &n, &m);

		}
//		N--;
//		if(N>0) 
//		   printf("\n");
	}
	return 0;
}
int find_sum(int n, int m)
{
	int i, j, sum=0;
	for(i=1;i<n;i++)
		for (j = i + 1; j < n; j++) {
			if ((i*i + j*j + m) % (i*j) == 0)
				sum++;
		}
	return sum;
}

 //注意 !(n==0 && m==0)与n!=0&&m!=0不一样 ，这个点导致在oj上怎么都过不了 
 //疑惑？？？？按题目意思应该是n！=0&&m！=0时程序退出 
