#include<iostream>
using namespace std;
int iscorret(int hang,int lie,int*[]);
void Queue(int,int*[]); 
int main()
{
	int Q[4][4],i,j;//Q[4][4]����Ϊ��ִ洢�ʺ����λ�õ� 
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	     Q[i][j]=0;    //��ʼ����� 
    Queue(0,Q);
    return 0;
 }
int iscorret(int hang,int lie,int (*Q)[4])
{
	int i,j;
	for(i=hang,j=0;j<=lie;j++) //���Ƿ���ͬһ���ж� 
	   if(Q[i][j]==1&&j!=lie)
	      return 0;
	for(i=0,j=lie;i<=hang;i++) //���Ƿ���ͬһ���ж� 
	   if(Q[i][j]==1&&i!=hang)
	     return 0; 
 } 
 
    
