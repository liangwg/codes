#include<iostream>
using namespace std;
int iscorret(int hang,int lie,int*[]);
void Queue(int,int*[]); 
int main()
{
	int Q[4][4],i,j;//Q[4][4]是作为棋局存储皇后放置位置的 
	for(i=0;i<4;i++)
	  for(j=0;j<4;j++)
	     Q[i][j]=0;    //初始化棋局 
    Queue(0,Q);
    return 0;
 }
int iscorret(int hang,int lie,int (*Q)[4])
{
	int i,j;
	for(i=hang,j=0;j<=lie;j++) //对是否在同一行判断 
	   if(Q[i][j]==1&&j!=lie)
	      return 0;
	for(i=0,j=lie;i<=hang;i++) //对是否在同一列判断 
	   if(Q[i][j]==1&&i!=hang)
	     return 0; 
 } 
 
    
