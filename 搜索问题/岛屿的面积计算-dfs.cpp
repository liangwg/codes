//����:a[m][n]�洢һƬ����0������1~9����½�أ�����ʼ������½�ص���� 

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
 void dfs(int x,int y)     //��ʱ��dfsû�б߽��ж�,����ĳһ��·������,ֱ����·�����е�����鶼������� 
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
			dfs(tx,ty);      //�ݹ����ʱ������ȡ��book[tx][ty]�ģ�ÿ����ֻ�ǳ���һ�� 
		 } 
 	    	
	}
	
	
	return ;    //�˴�����Ҫ,�ǵݹ���õĽ����ж� 
 } 
