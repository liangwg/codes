//问题:a[m][n]存储一片区域，0代表海洋，1~9代表陆地，求起始点所在陆地的面积 

#include<iostream>
using namespace std;
struct queue{
	int x;
	int y;
	
};
int main()
{
	int book[51][51]={0};// 标记存储数组 
	int a[51][51];//地图存储数组
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//方向数组
	
	
	int m,n;
	cin>>m>>n;
	int startx,starty;
		cin>>startx>>starty;
	int i,j;
	for(i=1;i<=m;i++)
	   for(j=1;j<=n;j++)
	      cin>>a[i][j] ;
	

	
	book[startx][starty]=1;
	int head=1,tail=1;
	queue qu[2501];
	qu[tail].x=startx;
	qu[tail].y=starty;
	tail++;
	
	int sum=1; //初始化是1是因为降落地点算一个
		int tx,ty,k;
	while(head<tail)
	{
	
		for(k=0;k<=3;k++)  //注意这里的小于等于号 
		{
			tx=qu[head].x+next[k][0];
			ty=qu[head].y+next[k][1];
			
			if(tx<1||tx>m||ty<1||ty>n)
			  continue;
			
			if((a[tx][ty]>0)&&book[tx][ty]==0)
			{
		
				sum++;
				book[tx][ty]=1;
				qu[tail].x=tx;
				qu[tail].y=ty;
		
				tail++;
				
			}
		}
		head++;
	 } 
	 
	 cout<<sum;
	
	
 } 
