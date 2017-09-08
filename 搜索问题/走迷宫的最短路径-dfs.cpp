#include<iostream>
using namespace std;
void dfs(int,int,int);
int aim_x,aim_y,n,m,minstep=99999999;//n表示地图的n行,m表示地图的m列,minstep表示最小步数
int book[51][51]={0};  //标记数组,表示是否走过
int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//分别表示向右，向左，向下，向上,此处很重要 
int a[51][51];//存储迷宫的地图 
int main()
{
	int i,j;
	cout<<"行数:";
	cin>>n;
	cout<<"列数:";
	cin>>m;
	for(i=1;i<=n;i++)     //注意这里是从1开始,一般都不用0的位置 
	  for(j=1;j<=m;j++)
	     cin>>a[i][j];  //输入地图相关情况 
	 cout<<"输入起始位置:"; 
	 int start_x,start_y;
	 cin>>start_x>>start_y;
	 cout<<"输入终点位置:";
	 cin>>aim_x>>aim_y;
	 
	 book[start_x][start_y]=1;//起始点不能用 
	 dfs(start_x,start_y,0);
	 cout<<minstep;
	 return 0;
 } 
 
 void dfs(int x,int y,int step)
 {
 	if(x==aim_x&&y==aim_y)
 	{
 		if(step<minstep)
		 {
		 	minstep=step;
			  
		 } 
 		return ;
	 }
	 int k,tx,ty;
	 for(k=0;k<4;k++)         //只要能列举出四次移动就行 
	 {
	 	tx=x+next[k][0]; //表示假设移动
	 	ty=y+next[k][1];
	 	
	 	if(tx<1||tx>n||ty<1||ty>m)   //此处很重要,判断下一步是否越界 
		   continue;
		    
	 	if(a[tx][ty]==0&&book[tx][ty]==0)   //判断是否有障碍物且是否之前移动过 
		 {
		 	
		 	                            //step++;
		 	book[tx][ty]=1;  //标记这个点已经走过 
		 	dfs(tx,ty,step+1);     //当前的位置状态递归到下一次状态 , 当前x,y,与已走过的步数step 
		 	book[tx][ty]=0;
		  } 
	 	
	 }
	 return;         //注意这里的return 
 }
