#include<iostream>
using namespace std;
int e[101][101],book[101],que[10001];
int main()
{
	int n,m;//n��ʾ�ж��ٸ��ڵ㣬m��ʾ�ڵ�֮�������ı��� 
	cin>>n>>m;
	int i,j;
	//��ʼ���ٽӾ���
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
		    {
		    	if(i!=j)
		    	   e[i][j]=99999999;
		    	else
		    	   e[i][j]=0;
			 }
	//�������������� 
	int num1,num2; 
	for(i=1;i<=m;i++)
	{
		cin>>num1>>num2;
		e[num1][num2]=1;
	}
	//������ʼ�� 
	int head=1,tail=1;
	que[tail]=1;
	tail++;
	book[1]=1;
	
	while(head<tail)
	{
		int cur=que[head];
		for(i=1;i<=n;i++)
		{
			if(e[cur][i]==1&&book[i]==0) //��Ѱ���ڵ� 
			{
				que[tail]=i;
				tail++;
				book[i]=1;
			}
		}
		if(tail>n)      //��ʾ�Ѿ�����n��,�������нڵ��Ѿ��������� 
		   break;
		head++;//�˴���ָ��һ��������չ���,Ҫhead++�Ա���չ����һ������ 
	}
	
	for(i=1;i<=n;i++)
	   cout<<que[i]<<" ";
	 return 0; 
} 
