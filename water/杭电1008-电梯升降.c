#include<stdio.h>
int elevator();
int main()
{
	int N,i,sum_T=0;
	int move[100];
	scanf("%d",&N);
	while(N!=0){
		move[0]=0;      
		for(i=0;i<N;i++)
		  scanf("%d",&move[i+1]);
    sum_T=elevator(move,N);
	printf("%d\n",sum_T);    //注意这里的\n 
	scanf("%d",&N); 
	}
	return 0;
 } 
 
 int elevator(int move[],int N)    //计算时间的规则，停留时间后期一并算掉，i和j是两个楼层之间的移动 
 {
 	int i,j,T=0;
 	for(i=0,j=i+1;j<=N;i++,j++){
 		if(move[i]>move[j])
 		    T=T+4*(move[i]-move[j]);
 		else
 		    T+=6*(move[j]-move[i]);
	 }
	 return T+N*5;
 }
 
// presentation error
// 意为输出格式错误，也就是你的输出没有按照输出要求进行格式化。一般是多了或者少了一些空格或者空行。
//
//一种做法是判断改组数据是否是第一组，如果不是的话，在输出答案之前加一个空行。
//
//常见的PE错误应该有以下的几种情况：?每行输出之后有空行
//每两行输出之间有空行
//一行中，每个输出数字（或字符串，等）之间有空格
//一行中，每个输出数字（或字符串，等）之后有空格
//自己把这几种情况的解决方法归纳以下，然后读题的时候多注意一下一般不会再出问题了。
