#include<iostream>
using namespace std;
int e[101][101],book[101],que[10001];
int main()
{
	int n,m;//n表示有多少个节点，m表示节点之间相连的边数 
	cin>>n>>m;
	int i,j;
	//初始化临接矩阵
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
		    {
		    	if(i!=j)
		    	   e[i][j]=99999999;
		    	else
		    	   e[i][j]=0;
			 }
	//输入矩阵的相连点 
	int num1,num2; 
	for(i=1;i<=m;i++)
	{
		cin>>num1>>num2;
		e[num1][num2]=1;
	}
	//处理起始点 
	int head=1,tail=1;
	que[tail]=1;
	tail++;
	book[1]=1;
	
	while(head<tail)
	{
		int cur=que[head];
		for(i=1;i<=n;i++)
		{
			if(e[cur][i]==1&&book[i]==0) //搜寻相邻点 
			{
				que[tail]=i;
				tail++;
				book[i]=1;
			}
		}
		if(tail>n)      //表示已经超过n了,表明所有节点已经被访问了 
		   break;
		head++;//此处是指当一个顶点扩展完后,要head++以便扩展到另一个顶点 
	}
	
	for(i=1;i<=n;i++)
	   cout<<que[i]<<" ";
	 return 0; 
} 
