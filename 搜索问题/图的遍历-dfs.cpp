#include<iostream>
using namespace std;
void dfs(int);
int book[101],e[101][101],n,m,sum=0;//n��ʾ�ڽӾ���ı�,m��ʾҪ�������
                                //ͨͼ������·�ߵĸ���,��ʱ�ı������book��һά�� 
                                //sum��ʾ�߷õĵ�ĸ���������ﵽnʱ��ʾ�߷��������еĵ� 
int main()
{
	cout<<"m=";
	cin>>m;
	cout<<"n=";
	cin>>n;
	int i,j;
	//��ʼ���ڽӾ���
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      {
	      	if(i==j)
			  e[i][j]=0;
			 else
			    e[i][j]=999999; 
		   }
	
	int k,t;//��ʾk��t֮������ͨ·�� 
	for(i=1;i<=m;i++)
	 {
	 	cin>>k>>t;
		 e[k][t]=1;  //����������ͼ������Ҫ��[k][t],[t][k] 
		 e[t][k]=1; 
	  }
	  book[1]=1; 
	  sum=1; 
	 dfs(1); 	
 } 
 
 void dfs(int x)
 {
 	cout<<x;
 	if(sum==n)
 	   return;
 	int i;
 	for(i=1;i<=n;i++)
 	  {
 	  	if(e[x][i]==1&&book[i]==0)  //�������ͨx->i��iû���߹��Ļ� 
 	  	{
 	  		book[i]=1;
 	  		sum++;
 	  		dfs(i);
		   }
	   }
	return ;
 	
 }
