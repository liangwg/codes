#include<stdio.h>
int main()
{
	float num[12]={0.0},sum=0.0;
	int i;
	for(i=0;i<12;i++)
	 {
	     scanf("%f",&num[i]);
	       sum+=num[i];
	   }
	printf("$%.2f\n",sum/12);
 } 
