#include<iostream>
using namespace std;
int e[101][101],book[101],n,m;//n��ʾ���Ҫ����ĳ���,һ���Ŀ����ж������һ����m��ʾ����֮���ж�����·,����· 
                                //�ĳ���,�洢��e[101][101]������
int minc=99999999; //��ʾ��С·������ 
void dfs(int cur,int dis) ;  //cur��ʾ��ǰ���ڵĳ���,dis��ʾ֮ǰ���߹���·��֮�� 
int main()
{
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      if(i==j)
			  e[i][j]=0;
		else 
		    e[i][j]=999999999;
	int city1,city2,c1_to_c2;
	for(i=1;i<=m;i++)
	{
		cin>>city1>>city2>>c1_to_c2;
		e[city1][city2]=c1_to_c2; //����,�з���,��Ϊ����ͼ 
	}
	
	int dis=0;
	book[1]=1;
	dfs(1,0); //      ����ʼ���ж���1��ų��� 
		
	cout<<minc;	 
	 
}
void dfs(int cur,int dis)
{
	if(dis>minc)  //���dis���ڴ�ʱ��min����û�м����ݹ�ı�Ҫ�� 
	  return;
	if(cur==n)
	  {
	  	if(dis<minc)
	  	   minc=dis;
			return; 
	  	    
	  }
	  
	  int i;
	  for(i=1;i<=n;i++)
	  {
	  	if(e[cur][i]!=999999999&&book[i]==0)
	  	{
	  		book[i]=1;
	  		dfs(i,dis+e[cur][i]);
	  		book[i]=0;
	  		
		  } 
	  
       }
       return;
 } 
