#include<iostream>
using namespace std;
struct qu{          
	int x;
	int y;
	int father;  //�洢·���ı��� 
	int step;   //�洢�����ı��� 
};
int main()
{
	//��ʼ����������: 
	int m,n,i,j;
	int a[51][51];       //��ͼ���� 
	int book[51][51]={0};      //������� 
	int next[4][2]={{0,1},{1,0},{-1,0},{0,-1}}; //�������� 
	struct qu que[2501]; // ���д洢 �������� 
	int  head=1;
	int tail=1;
	
	//���벿�� 
	cout<<"����:";
	cin>>m;
	cout<<"����:";
	cin>>n;
	for(i=1;i<=m;i++)
	  for(j=1;j<=n;j++)
	     cin>>a[i][j];
	cout<<"��ʼλ�� �յ�λ��:";
	int start_x,start_y,aim_x,aim_y; 
	cin>>start_x>>start_y>>aim_x>>aim_y;
	
	book[start_x][start_y]=1;  //����ʼ����д���,ʹ���� 
	que[tail].x=start_x;
	que[tail].y=start_y;
	que[tail].step=0;
	que[tail].father=head;
	tail++;
	
	int flag=0;     //�Ƿ񵽴�Ŀ�ĵص��ж� 
	while(head<tail)
	{
		int tx,ty,k;
		//���쵽��һ���� 
		for(k=0;k<3;k++)
		{
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			if(tx<1||tx>m||ty<1||ty>n)  //Խ���ж� 
			    continue;
			
			if(a[tx][ty]==0&&book[tx][ty]==0)  //����һ����Ĺ�Ӵ��� 
			  {
			  	book[tx][ty]=1;
			  	que[tail].x=tx;
			  	que[tail].y=ty;
			  	que[tail].step=que[head].step+1;
			  	que[tail].father=head;
			  	tail++;
			  	
			  }
			  //�Ƿ���Ŀ�����ж� 
			if(tx==aim_x&&ty==aim_y) 
			{
				flag=1;
				break;
			} 
		}
		if(flag==1)
		    break;
		head++;  //���¸��������չ 
	 }
	 cout<<que[tail-1].step; 
	
	
	
	
	
	
	
 } 
