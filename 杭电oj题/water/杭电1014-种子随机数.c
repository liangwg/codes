#include<stdio.h>
int judge();
int main()
{
	int step,mod;
	while(scanf("%d%d",&step,&mod)!=-1){
		if(judge(step,mod))
		   printf("%10d%10d    Good Choice\n\n",step,mod);//ע�����ĸ��ո� 
		else
		   printf("%10d%10d    Bad Choice\n\n",step,mod);
    }
	return 0;
 } 
 
 int judge(int step,int mod)
 {
 	int seed[100009],i=1,j,count=1;
 	seed[0]=0;
 	seed[i]=(seed[i-1]+step)%mod;
 	while(seed[i]!=seed[0]){
 		i++;
 		seed[i]=(seed[i-1]+step)%mod;
 		count++;
	 }
	 
// 	for(i=0;state==0;i++){           //���ü�����е�ֻ����seed[0],���� 
// 		seed[i+1]=(seed[i]+step)%mod;
// 		for(j=0;j<i+1;j++)
// 		    if(seed[j]==seed[i+1])
// 		        state=1;
	 if(count==mod)        
	   return 1;
	else
	    return 0;
 }
