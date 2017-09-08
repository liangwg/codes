#include<iostream>
using namespace std;
struct qu{          
	int x;
	int y;
	int father;  //存储路径的变量 
	int step;   //存储步数的变量 
};
int main()
{
	//初始化定义区域: 
	int m,n,i,j;
	int a[51][51];       //地图数组 
	int book[51][51]={0};      //标记数组 
	int next[4][2]={{0,1},{1,0},{-1,0},{0,-1}}; //方向数组 
	struct qu que[2501]; // 队列存储 队列数组 
	int  head=1;
	int tail=1;
	
	//输入部分 
	cout<<"行数:";
	cin>>m;
	cout<<"列数:";
	cin>>n;
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	     cin>>a[i][j];
	cout<<"起始位置 终点位置:";
	int start_x,start_y,aim_x,aim_y; 
	cin>>start_x>>start_y>>aim_x>>aim_y;
	
	book[start_x][start_y]=1;  //对起始点进行处理,使其归队 
	que[tail].x=start_x;
	que[tail].y=start_y;
	que[tail].step=0;
	que[tail].father=head;
	tail++;
	
	int flag=0;     //是否到达目的地的判断 
	while(head<tail)
	{
		int tx,ty,k;
		//延伸到下一个点 
		for(k=0;k<3;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			if(tx<1||tx>m||ty<1||ty>n)  //越界判断 
			    continue;
			
			if(a[tx][ty]==0&&book[tx][ty]==0)  //对下一个点的归队处理 
			  {
			  	book[tx][ty]=1;
			  	que[tail].x=tx;
			  	que[tail].y=ty;
			  	que[tail].step=que[head].step+1;
			  	que[tail].father=head;
			  	tail++;
			  	
			  }
			  //是否是目标点的判断 
			if(tx==aim_x&&ty==aim_y) 
			{
				flag=1;
				break;
			} 
		}
		if(flag==1)
		    break;
		head++;  //对下个点进行扩展 
	 }
	 cout<<que[tail-1].step; 
	
	
	
	
	
	
	
 } 
