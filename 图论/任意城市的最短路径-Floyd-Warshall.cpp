#include<iostream>
using namespace std;
#define inf 999999 //�����ı�ʾ�� 
int main()
{
	int e[101][101],i,j,m,n;//m��ʾ�м�������,n��ʾ����֮��Ĺ�·��,e[101][101]�洢��������ͼ 
	cin>>m>>n;
	//��ʼ���ڽӾ��� 
	for(i=1;i<=m;i++)
	   for(j=1;j<=m;j++)
	      if(i==j)
	         e[i][j]=0;
	       else
	          e[i][j]=inf;
	 
	 int x1,x2,dis;
	for(i=1;i<=n;i++)
	{
		cin>>x1>>x2>>dis;
		e[x1][x2]=dis;	
	}
	int k;
	//Floyd-Warshall�㷨�ĺ��Ĳ���  �����м���ɵ��ж���ֱ��ȥ�����м�ӹ��ɵ��·����� 
	for(k=1;k<=m;k++)        //�㷨�߼�,��С���� 
	   for(i=1;i<=m;i++)
	     for(j=1;j<=m;j++)
		     if(e[i][k]<inf&&e[k][j]<inf&&e[i][j]>e[i][k]+e[k][j])
			       e[i][j]=e[i][k]+e[k][j];
	
	for(i=1;i<=m;i++)
	{
	    for(j=1;j<=m;j++)
	      cout<<e[i][j]<<" ";
		cout<<endl; 
    }
 } 
 //Floyd-Warshall�㷨������������ͼ����������֮������·��,Ҳ��������ָ������֮������·��,(dfs,bfs����) 
 //������������ָ����һ���㵽���������·�� 
 //���㷨����������ͼ�д��и�Ȩ��·������ͼ 
