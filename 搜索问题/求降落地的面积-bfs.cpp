//����:a[m][n]�洢һƬ����0������1~9����½�أ�����ʼ������½�ص���� 

#include<iostream>
using namespace std;
struct queue{
	int x;
	int y;
	
};
int main()
{
	int book[51][51]={0};// ��Ǵ洢���� 
	int a[51][51];//��ͼ�洢����
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//��������
	
	
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
	
	int sum=1; //��ʼ����1����Ϊ����ص���һ��
		int tx,ty,k;
	while(head<tail)
	{
	
		for(k=0;k<=3;k++)  //ע�������С�ڵ��ں� 
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
