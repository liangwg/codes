#include<stdio.h>
int find_sum(int,int);
int main()
{
	int N, n, m, sum;
	
	scanf("%d", &N);  //����ģ������
	int temp=N-1;
	int i = 1;
	//printf("\n");
	while (N != 0) {
		N--;
		if(N<temp)
		   printf("\n");  //����ע���ʽ���⣬ÿ�������֮�䶼��һ�� 
		 i = 1;
		scanf("%d%d", &n, &m);
		while (!(n==0 && m==0)) {          //ע�� !(n==0 && m==0)��n!=0&&m!=0��һ�� 
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

 //ע�� !(n==0 && m==0)��n!=0&&m!=0��һ�� ������㵼����oj����ô�������� 
 //�ɻ󣿣���������Ŀ��˼Ӧ����n��=0&&m��=0ʱ�����˳� 
