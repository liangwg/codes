#include<iostream>
#define inf 9999999
using namespace std;
int main()
{
	int e[101][101],dis[101]={0},i,j,city,road,book[101]={0}; //ע������ı���ȡ��,��Ҫȡm,n,�����������Ū��� 
	//�����ж��ٸ�����,������֮��ĵ�·
	cin>>city>>road;
	//��ʼ���ڽӾ��� 
	for(i=1;i<=city;i++)
	 {
	  for(j=1;j<=city;j++)
	     if(i==j)
	        e[i][j]=0;
	     else e[i][j]=inf;
	}
	//�������֮��ĵ�·
	int tx,ty,d;
	for(i=1;i<=road;i++)
	{
		cin>>tx>>ty>>d;
		e[tx][ty]=d; 
	} 
	//��ʼ��dis����, 
	for(i=1;i<=city;i++)
	   dis[i]=e[1][i];
	for(i=1;i<=city;i++)
      cout<<dis[i]<<" ";
	//����P��Q���ϵ�Ǩ��
	int min,u;
	int count=1;//���� 
	book[1]=1;
	//�㷨�ĺ��Ĳ��� 
	while(count<city)
	{    //�ҵ�P������ĵ�1����С����,���ȷ��ֵ
//	     min=2;
//	    for(i=2;i<=n;i++)
//	    {
//		    if(dis[min]>dis[i]&&book[i]==0)
//		    {
//			    min=i;
//		     }
//	    } 
//	    book[min]=1;//���õ�ӵ�Q������ 

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
	    //�����ɳ�
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

//Dijkstra�㷨С̸:1.���������:����ͼ�����е㵽ĳ����������·��,��������Ȩ�� 
                   //2.���·���洢��dis[]������,��ʼ��ʱ�ǹ���ֵ,�輯��P�ǹ���ֵ,Q��ȷ��ֵ,����P���Ҿ��붨�����
				      //�ĵ�,���뵽Q������,ͨ���õ����ɳ�P��������㵽�����·�� 
				          // if(dis[u]+e[u][i]<dis[i])
			    	              //dis[i]=dis[u]+e[u][i];
			    	//Ȼ������P�������������,ѭ�����ϲ��� 
			    	//�����֮,P->Q,��Ѱ,����,�ɳ� 
