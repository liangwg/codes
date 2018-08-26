#include<stdio.h>
#include<math.h>
#include<string.h> 
void change_to_A();
int main()
{
	int  v,x,w,y,z,i,num[20],len,state=0;   //num存储转化后的对应的数字 
	char input[20]={'\0'},temp[5],max[5]; //input[]存储输入的字母限制区,max[]存储输出的对应最优解,temp[]存 
	int target;
	scanf("%d",&target);                                   //储暂时的解 
	while(target!=0&&input!="END"){
		state=0;           //	清空上一次循环留下的影响 
		memset(input,0,sizeof(char));
		memset(max,0,sizeof(char));
		memset(temp,0,sizeof(char));
		memset(num,0,sizeof(int));   
		getchar();  //吃掉空格符号 
		gets(input);
		len=strlen(input);        //获得长度 
		for(i=0;i<len;i++){    //将待选字符串转化为对应的数字 
			num[i]=(input[i]-'A')+1;
		}
	
		for(v=0;v<len;v++)       //穷举法 ,能力有限，想不到更优的方法 
		    for(w=0;w<len;w++)
			   for(x=0;x<len;x++)
			     for(y=0;y<len;y++) 
			     	for(z=0;z<len;z++)                                               //注意v,w,x,y,z不能相等 
			     	if(num[v]-pow(num[w],2.0)+pow(num[x],3.0)-pow(num[y],4.0)+pow(num[z],5.0)==target&&v!=w&&v!=x&&v!=y&&v!=z&&w!=x&&w!=y&&w!=z&&x!=y&&x!=z&&y!=z){
			     		state=1;                    //表示有解 
			     		change_to_A(v,w,x,y,z,temp,num);
						 if(strcmp(temp,max))
						       strcpy(max,temp); 
				}
		if(state==1)
		   printf("%s\n",max);
		else
		   printf("no solution\n"); 
		scanf("%d",&target);
				 
		
	}
	return 0;
 } 
 void change_to_A(int v,int w,int x,int y,int z,char*temp,int num[]) 
 {
 	
 	    temp[0]=num[v]-1+'A';
 	    temp[1]=num[w]-1+'A';
 	    temp[2]=num[x]-1+'A';
 	    temp[3]=num[y]-1+'A';
 	    temp[4]=num[z]-1+'A';
}
  
  
 
  
