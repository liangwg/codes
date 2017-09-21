#include<iostream>
#define inf 9999999
using namespace std;
int main()
{
	int e[101][101],dis[101]={0},i,j,city,road,book[101]={0}; //注意这里的变量取名,不要取m,n,到后面很容易弄混掉 
	//输入有多少个城市,及城市之间的道路
	cin>>city>>road;
	//初始化邻接矩阵 
	for(i=1;i<=city;i++)
	 {
	  for(j=1;j<=city;j++)
	     if(i==j)
	        e[i][j]=0;
	     else e[i][j]=inf;
	}
	//输入城市之间的道路
	int tx,ty,d;
	for(i=1;i<=road;i++)
	{
		cin>>tx>>ty>>d;
		e[tx][ty]=d; 
	} 
	//初始化dis数组, 
	for(i=1;i<=city;i++)
	   dis[i]=e[1][i];
	for(i=1;i<=city;i++)
      cout<<dis[i]<<" ";
	//进行P到Q集合的迁移
	int min,u;
	int count=1;//计数 
	book[1]=1;
	//算法的核心部分 
	while(count<city)
	{    //找到P集合里的到1的最小距离,变成确定值
//	     min=2;
//	    for(i=2;i<=n;i++)
//	    {
//		    if(dis[min]>dis[i]&&book[i]==0)
//		    {
//			    min=i;
//		     }
//	    } 
//	    book[min]=1;//将该点加到Q集合里 

        min=inf;
        for(i=1;i<=city;i++)
		{
			if(book[i]==0&&dis[i]<min)
			{
				min=dis[i];
				u=i;
			}
		 } 
		 book[u]=1;
	    //进行松弛
		for(i=1;i<=city;i++)
		{
			if(e[u][i]<inf)
		  {
			if(dis[u]+e[u][i]<dis[i])
			    	dis[i]=dis[u]+e[u][i];
			}
		 } 
		count++;
	 }  
	 for(i=1;i<=city;i++)
	 {
	    cout<<dis[i]<<" ";
     }
} 

//Dijkstra算法小谈:1.解决的问题:有向图里所有点到某个定点的最短路径,不包括负权边 
                   //2.最短路径存储在dis[]数组里,初始化时是估计值,设集合P是估计值,Q是确定值,先在P中找距离定点最近
				      //的点,加入到Q集合中,通过该点来松弛P中其余各点到定点的路径 
				          // if(dis[u]+e[u][i]<dis[i])
			    	              //dis[i]=dis[u]+e[u][i];
			    	//然后再在P集合中找最近点,循环以上步骤 
			    	//简而言之,P->Q,找寻,加入,松弛 
