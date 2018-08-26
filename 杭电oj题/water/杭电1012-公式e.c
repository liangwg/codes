#include<stdio.h>
double Formula();
int main()
{
	int N=9,i;
	double sum;
	printf("n e\n- -----------\n");
	 for(i=0;i<=N;i++){
	 	sum=Formula(i);
	 	if(i<=1)
	 	  printf("%d %.0lf\n",i,sum);   //注意输出格式问题 
	 	else if(i==2)
	 	   printf("%d %.1lf\n",i,sum);
	 	   else
	 	      printf("%d %.9lf\n",i,sum);
		     
	 }
	 return 0;
} 

double Formula(int n)
{
	static int i=1;
	static double sum;
	if(n==0)
	  sum=1;
	else{
		i=i*n;
		sum=sum+(double)1/i; 
	}
	return sum;
}
