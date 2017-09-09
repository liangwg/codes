//问题:a[m][n]存储一片区域，0代表海洋，1~9代表陆地，求起始点所在陆地的面积 

#include<iostream>
using namespace std; 
void dfs(int ,int);
int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int a[51][51];
int book[51][51];
int sum=0,m,n;
int main()
{
	cin>>m>>n;
	int startx,starty;
	cin>>startx>>starty;
	int i,j;
	for(i=1;i<=m;i++)
	   for(j=1;j<=n;j++)
	       cin>>a[i][j];
	
	book[startx][starty]=1;
	sum=1;
	dfs(startx,starty);
	cout<<sum;
	
	
 } 
 void dfs(int x,int y)     //此时的dfs没有边界判断,是由某一个路径出发,直到该路径所有的面积块都被计算过 
 {
 	int k,tx,ty;
 	for(k=0;k<=3;k++)
 	{
 		tx=x+next[k][0];
 		ty=y+next[k][1];
 		
 		if(tx<1||tx>m||ty<1||ty>n)
		    continue;
		
		if(a[tx][ty]>0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			sum++;
			dfs(tx,ty);      //递归回来时不用再取消book[tx][ty]的，每个点只是尝试一次 
		 } 
 	    	
	}
	
	
	return ;    //此处很重要,是递归调用的结束判断 
 } 
