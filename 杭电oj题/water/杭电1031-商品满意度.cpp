#include<iostream>
#include<algorithm>
using namespace std;

struct element{
	float sum;
	int num;
};
int cmp1(element &a,element &b)
{
	if(a.sum>b.sum)
	   return 1;
	else if(a.sum==b.sum)
	     {
	     	if(a.num<b.num)
	     	   return 1;
	     	else
	     	   return 0;
		
	     }
	     else
	        return 0;
}
int cmp2(int &a,int &b)
{
	return a>b;
}
	float a[500][500]; //注意这里,不能用动态数组的方式,只能用开最大情况方法 
	int out[500];
	element b[500];
int main()
{
	int N,M,K; 
  while(scanf("%d %d %d",&N,&M,&K)!=EOF)
    {


	int i,j;

	for(i=0;i<N;i++)	
	   for(j=0;j<M;j++)
	      cin>>a[i][j];
     
     for(j=0;j<M;j++)       //
     {
     	b[j].num=j+1;
     	b[j].sum=0;
     	for(i=0;i<N;i++)
     	 {
     	 	b[j].sum=b[j].sum+a[i][j];
		  }
	 }
    sort(b,b+M,cmp1);  //这里用c++自带的排序函数更加方便 
	
	for(i=0;i<K;i++)
	    out[i]=b[i].num;
	sort(out,out+K,cmp2);
	for(i=0;i<K;i++)
	{
		if(i!=K-1)
		   cout<<out[i]<<" ";
		 else
		    cout<<out[i]<<endl; 
		
		 }	 

  }

	
	
}
