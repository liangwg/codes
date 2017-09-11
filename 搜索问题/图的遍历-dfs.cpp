#include<iostream>
using namespace std;
void dfs(int);
int book[101],e[101][101],n,m,sum=0;//n表示邻接矩阵的边,m表示要输入的连
                                //通图的连接路线的个数,此时的标记数组book是一维的 
                                //sum表示走访的点的个数，当点达到n时表示走访完了所有的点 
int main()
{
	cout<<"m=";
	cin>>m;
	cout<<"n=";
	cin>>n;
	int i,j;
	//初始化邻接矩阵
	for(i=1;i<=n;i++)
	   for(j=1;j<=n;j++)
	      {
	      	if(i==j)
			  e[i][j]=0;
			 else
			    e[i][j]=999999; 
		   }
	
	int k,t;//表示k和t之间有连通路径 
	for(i=1;i<=m;i++)
	 {
	 	cin>>k>>t;
		 e[k][t]=1;  //由于是无向图，所以要有[k][t],[t][k] 
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
 	  	if(e[x][i]==1&&book[i]==0)  //如果有连通x->i且i没有走过的话 
 	  	{
 	  		book[i]=1;
 	  		sum++;
 	  		dfs(i);
		   }
	   }
	return ;
 	
 }
