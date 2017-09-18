#include<iostream>
using namespace std;
#define inf 999999 //无穷大的表示法 
int main()
{
	int e[101][101],i,j,m,n;//m表示有几个城市,n表示城市之间的公路数,e[101][101]存储的是有向图 
	cin>>m>>n;
	//初始化邻接矩阵 
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
	//Floyd-Warshall算法的核心部分  ，加中间过渡点判断是直接去还是中间加过渡点的路径最短 
	for(k=1;k<=m;k++)        //算法高级,短小精悍 
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
 //Floyd-Warshall算法可用来求有向图中任意两点之间的最短路径,也可用来求指定两点之间的最短路径,(dfs,bfs更快) 
 //还可以用来求指定的一个点到任意点的最短路径 
 //此算法不能用来求图中带有负权回路的有向图 
