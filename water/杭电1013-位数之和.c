#include<stdio.h>
int len();
int root();
int seat[10000];
int main()
{
	int i,lengh, num=0;  
	char string[100000]={'\0'};   //存储大数 
	gets(string);
	
	for(i=0;string[i];i++){    //实现对大数第一次位数相加运算，加出来的必是可以储存的数 
		num=num+(string[i]-'0'); 
	}
	//scanf("%d",&num);         //没有考虑大数， 
	while(num!=0){
		lengh=len(num);
		printf("%d\n",root(num,lengh));
	//	scanf("%d",&num);
	    for(i=0;i<100000;i++)
	          string[i]='\0';//清空存储大数的数组，存储下一次大数 
	    gets(string);
	    num=0;
	    for(i=0;string[i];i++)
	        num=num+(string[i]-'0'); 
    }
        return 0;
 } 
 
 int len( int num)    //计算位数 
 {
 	int i=0;
 	while(num!=0){
 		i++;
 		num=num/10;
	 }
	 return i;
 }
 
 int root(int num,int lengh)  //规则函数，递归法 
 {
 	int sum=0,le,i; 
 	if(lengh==1)
 	   return num;
 	else{
 		for(i=0;i<lengh;i++){
 			seat[i]=num%10;
 			num=num/10;
 			sum=sum+seat[i];
		 }
		 le=len(sum);
		 root(sum,le);
		 
		 
 		
	 }
 }
 
 
 //此题注意大数的输入，应用字符数组来存储大数。然后再位数相加，加完后的可以视为输入了整形变量int型数来处理
 //用递归法解决后面的问题 
