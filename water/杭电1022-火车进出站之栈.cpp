
#include<stdlib.h>
#include<stdio.h>
#define MAX 20 
struct stack{
	int st[MAX+1];
	int top;    //头部的指针 
};
int Get_Top(stack); //取栈顶元素观看 
void Pop(stack&);
void Push(stack&,int);
int is_Empty(stack);
void input(int*,int*);  //读入火车进栈消息 

int main()
{
	stack S;  //定义栈 
	
	int num; 
	int t;
	int print[MAX*2+3];  //打印进栈顺序,1表示进栈，0表示出栈 
	int in[MAX+1];
	int out[MAX+1];  //存储输入的火车进出顺序 
	while(scanf("%d",&num)!=EOF)
	{
		for(t=1;t<=MAX+1;t++)  //对进栈数组初始化 
		{
			in[t]=0;
		}
		S.top=1;  //对栈初始化 ，每次都要初始化 
		int i=1,j=1,k=1,flag=0;
	    getchar();
	    input(in,out);
	    for(i=1;i<=num+1;)
	    {
	    	if(is_Empty(S))
	    	{
	    		if(in[i]==0)  //这边真的很难想，由于是整形数组，超过num时仍然有数，再被压入栈中 ，导致下面的循环又要进行一次错误 
	    		{               //如果全部处理完了，保证循环能退出来 
	    			i++;
				}
				else
				{
	    		Push(S,in[i]);     //如果栈为空则处理第一个数据
	    		i++;
	    		print[k++]=1;
				} 
			}
			if(!is_Empty(S)&&Get_Top(S)!=out[j])
			{                     //如果栈不空并且不等于当前出站序列中的数字，则必须再将后面的标号入栈
				Push(S,in[i]);
				print[k++]=1;
				i++;
			}
			if(!is_Empty(S)&&Get_Top(S)==out[j])
			{                 //如果栈不为空，并且栈顶元素等于当前出站序列中的当前位置，则出栈，并让出站序列向后，开始处理下一个出站序列

				Pop(S);
				
				print[k++]=0;
				j++; 
			} 
		}
		if(!is_Empty(S))    //若栈不为空，说明有列车滞留在车站中，肯定不能实现题目给出的出站序列
		  printf("No.\n");
		else
		{ 
		   printf("Yes.\n");
		   for(i=1;i<=num*2;i++)
		   {
		   	  if(print[i]==1)
		   	     printf("in\n");
		   	else
		   	    printf("out\n");
			}   
		} 
		printf("FINISH\n");
	    
	 } 
 } 
 
 int Get_Top(stack S)
 {
 	return S.st[S.top-1];
 }
 void Pop(stack&S)
 {
 	S.top--;
 }
 void Push(stack&S,int e)
 {
 	S.st[S.top++]=e;
 } 
 int is_Empty(stack S)
 {
 	if(S.top==1)
 	   return 1;
 	else
 	   return 0;
 	
 }

 void input(int*in,int*out)
 {
 	char ch;
 	int i;
 	//进栈信息 
	 		i=1;
			scanf("%c",&ch); 
			
	         while(ch!=' ')
	         {
	         	in[i]=ch-'0';
	         	i++;
	         	scanf("%c",&ch);
			 }
			 //出栈信息 
			 scanf("%c",&ch);
			 i=1;
			 	while(ch!='\n')
			 	{
			 		out[i]=ch-'0';
			 		i++;
			 		scanf("%c",&ch); 
				 }
  } 
  
  //网上另一位大佬的代码： 
//  //AC代码：
//#include <iostream>
//#include <stack>
//using namespace std;
//int main()
//{
//    int n;
//    char in[100];
//    char out[100];
//    int flag[100];  //记录判断进站还是出站的标志
//    while(cin>>n)
//    {
//        cin>>in;
//        cin>>out;
//        stack<char> s;//模拟站台的栈
//        int i=0;      //i代表进站序列的对应列车
//        int j=0;      //j代表出站序列的对应列车
//        for(i;i<=n;)
//        {
//            if(s.empty())  //如果栈为空则处理第一个数据
//            {
//            	
//                s.push(in[i]);    //此处真的很神奇，即当in[i]已经不是火车序列时，in[i]="\0"push不进去的，但又保证了i++推出循环 
//                flag[i+j] = 0;
//                i++;          //第一个数据入栈，计数器加一
//            }
//            if(!s.empty()&&s.top()!=out[j])//如果栈不空并且不等于当前出站序列中的数字，则必须再将后面的标号入栈
//            {
//                s.push(in[i]);
//                flag[i+j] = 0;
//                i++;
//            }
//            if(!s.empty()&&s.top()==out[j])
//            {
//                s.pop();
//                flag[i+j] = 1;
//                j++;
//            }                             //如果栈不为空，并且栈顶元素等于当前出站序列中的当前位置，则出栈，并让出站序列向后，开始处理下一个出站序列
//        }
//        if(s.empty())                    //若栈为空，证明全部列车都已经出站，所以题目给出的出站序列有可能实现
//        {
//            cout<<"Yes."<<endl;
//            for(i=0;i<2*n;i++)
//            {
//                if(flag[i]!=1)cout<<"in"<<endl;
//                else cout<<"out"<<endl;
//            }
//            cout<<"FINISH"<<endl;
//        }
//        else                               //若栈不为空，说明有列车滞留在车站中，肯定不能实现题目给出的出站序列
//        {
//            cout<<"No."<<endl;
//            cout<<"FINISH"<<endl;
//        }
//    }
//    return 0;
//}

