#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 char color[1000][16];
 int num[1000]; 
 int n;
    scanf("%d",&n);
    while(n!=0){
      
     getchar();   //注意在每个scanf和gets之间注意回车键
     
  int i,j,max=0;
  for(i=0;i<n;i++){
        num[i]=0;
        memset(color[i],0,sizeof(color[i]));
  
  gets(color[i]);
  //puts(color[i]);
  }
  for(i=0;i<n;i++){
   for(j=i+1;j<n;j++){
    if(strcmp(color[i],color[j])==0)
          num[i]++;
   }
   max=(max>num[i]?max:num[i]);
  }
  i=0;
  while(max!=num[i])
      i++;
  puts(color[i]);
  
  
  
    scanf("%d",&n);
   
 }
 } 

