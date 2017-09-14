#include<iostream>
using namespace std;
int e[101][101],book[101],n,m;//n表示最后要到达的城市,一般把目标城市定做最后一个。m表示城市之间有多少条路,至于路 
                                //的长度,存储在e[101][101]数组中
int minc=99999999; //表示最小路径长度 
void dfs(int cur,int dis) ;  //cur表示当前所在的城市,dis表示之前所走过的路径之和 
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
		e[city1][city2]=c1_to_c2; //单向,有方向,即为有向图 
	}
	
	int dis=0;
	book[1]=1;
	dfs(1,0); //      把起始城市定做1编号城市 
		
	cout<<minc;	 
	 
}
void dfs(int cur,int dis)
{
	if(dis>minc)  //如果dis大于此时的min，就没有继续递归的必要了 
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
