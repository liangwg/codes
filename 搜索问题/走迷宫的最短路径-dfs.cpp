#include<iostream>
using namespace std;
void dfs(int,int,int);
int aim_x,aim_y,n,m,minstep=99999999;//n��ʾ��ͼ��n��,m��ʾ��ͼ��m��,minstep��ʾ��С����
int book[51][51]={0};  //�������,��ʾ�Ƿ��߹�
int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//�ֱ��ʾ���ң��������£�����,�˴�����Ҫ 
int a[51][51];//�洢�Թ��ĵ�ͼ 
int main()
{
	int i,j;
	cout<<"����:";
	cin>>n;
	cout<<"����:";
	cin>>m;
	for(i=1;i<=n;i++)     //ע�������Ǵ�1��ʼ,һ�㶼����0��λ�� 
	  for(j=1;j<=m;j++)
	     cin>>a[i][j];  //�����ͼ������ 
	 cout<<"������ʼλ��:"; 
	 int start_x,start_y;
	 cin>>start_x>>start_y;
	 cout<<"�����յ�λ��:";
	 cin>>aim_x>>aim_y;
	 
	 book[start_x][start_y]=1;//��ʼ�㲻���� 
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
	 for(k=0;k<4;k++)         //ֻҪ���оٳ��Ĵ��ƶ����� 
	 {
	 	tx=x+next[k][0]; //��ʾ�����ƶ�
	 	ty=y+next[k][1];
	 	
	 	if(tx<1||tx>n||ty<1||ty>m)   //�˴�����Ҫ,�ж���һ���Ƿ�Խ�� 
		   continue;
		    
	 	if(a[tx][ty]==0&&book[tx][ty]==0)   //�ж��Ƿ����ϰ������Ƿ�֮ǰ�ƶ��� 
		 {
		 	
		 	                            //step++;
		 	book[tx][ty]=1;  //���������Ѿ��߹� 
		 	dfs(tx,ty,step+1);     //��ǰ��λ��״̬�ݹ鵽��һ��״̬ , ��ǰx,y,�����߹��Ĳ���step 
		 	book[tx][ty]=0;
		  } 
	 	
	 }
	 return;         //ע�������return 
 }
