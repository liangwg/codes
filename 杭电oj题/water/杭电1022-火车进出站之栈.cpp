
#include<stdlib.h>
#include<stdio.h>
#define MAX 20 
struct stack{
	int st[MAX+1];
	int top;    //ͷ����ָ�� 
};
int Get_Top(stack); //ȡջ��Ԫ�عۿ� 
void Pop(stack&);
void Push(stack&,int);
int is_Empty(stack);
void input(int*,int*);  //����𳵽�ջ��Ϣ 

int main()
{
	stack S;  //����ջ 
	
	int num; 
	int t;
	int print[MAX*2+3];  //��ӡ��ջ˳��,1��ʾ��ջ��0��ʾ��ջ 
	int in[MAX+1];
	int out[MAX+1];  //�洢����Ļ𳵽���˳�� 
	while(scanf("%d",&num)!=EOF)
	{
		for(t=1;t<=MAX+1;t++)  //�Խ�ջ�����ʼ�� 
		{
			in[t]=0;
		}
		S.top=1;  //��ջ��ʼ�� ��ÿ�ζ�Ҫ��ʼ�� 
		int i=1,j=1,k=1,flag=0;
	    getchar();
	    input(in,out);
	    for(i=1;i<=num+1;)
	    {
	    	if(is_Empty(S))
	    	{
	    		if(in[i]==0)  //�����ĺ����룬�������������飬����numʱ��Ȼ�������ٱ�ѹ��ջ�� �����������ѭ����Ҫ����һ�δ��� 
	    		{               //���ȫ���������ˣ���֤ѭ�����˳��� 
	    			i++;
				}
				else
				{
	    		Push(S,in[i]);     //���ջΪ�������һ������
	    		i++;
	    		print[k++]=1;
				} 
			}
			if(!is_Empty(S)&&Get_Top(S)!=out[j])
			{                     //���ջ���ղ��Ҳ����ڵ�ǰ��վ�����е����֣�������ٽ�����ı����ջ
				Push(S,in[i]);
				print[k++]=1;
				i++;
			}
			if(!is_Empty(S)&&Get_Top(S)==out[j])
			{                 //���ջ��Ϊ�գ�����ջ��Ԫ�ص��ڵ�ǰ��վ�����еĵ�ǰλ�ã����ջ�����ó�վ������󣬿�ʼ������һ����վ����

				Pop(S);
				
				print[k++]=0;
				j++; 
			} 
		}
		if(!is_Empty(S))    //��ջ��Ϊ�գ�˵�����г������ڳ�վ�У��϶�����ʵ����Ŀ�����ĳ�վ����
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
 	//��ջ��Ϣ 
	 		i=1;
			scanf("%c",&ch); 
			
	         while(ch!=' ')
	         {
	         	in[i]=ch-'0';
	         	i++;
	         	scanf("%c",&ch);
			 }
			 //��ջ��Ϣ 
			 scanf("%c",&ch);
			 i=1;
			 	while(ch!='\n')
			 	{
			 		out[i]=ch-'0';
			 		i++;
			 		scanf("%c",&ch); 
				 }
  } 
  
  //������һλ���еĴ��룺 
//  //AC���룺
//#include <iostream>
//#include <stack>
//using namespace std;
//int main()
//{
//    int n;
//    char in[100];
//    char out[100];
//    int flag[100];  //��¼�жϽ�վ���ǳ�վ�ı�־
//    while(cin>>n)
//    {
//        cin>>in;
//        cin>>out;
//        stack<char> s;//ģ��վ̨��ջ
//        int i=0;      //i�����վ���еĶ�Ӧ�г�
//        int j=0;      //j�����վ���еĶ�Ӧ�г�
//        for(i;i<=n;)
//        {
//            if(s.empty())  //���ջΪ�������һ������
//            {
//            	
//                s.push(in[i]);    //�˴���ĺ����棬����in[i]�Ѿ����ǻ�����ʱ��in[i]="\0"push����ȥ�ģ����ֱ�֤��i++�Ƴ�ѭ�� 
//                flag[i+j] = 0;
//                i++;          //��һ��������ջ����������һ
//            }
//            if(!s.empty()&&s.top()!=out[j])//���ջ���ղ��Ҳ����ڵ�ǰ��վ�����е����֣�������ٽ�����ı����ջ
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
//            }                             //���ջ��Ϊ�գ�����ջ��Ԫ�ص��ڵ�ǰ��վ�����еĵ�ǰλ�ã����ջ�����ó�վ������󣬿�ʼ������һ����վ����
//        }
//        if(s.empty())                    //��ջΪ�գ�֤��ȫ���г����Ѿ���վ��������Ŀ�����ĳ�վ�����п���ʵ��
//        {
//            cout<<"Yes."<<endl;
//            for(i=0;i<2*n;i++)
//            {
//                if(flag[i]!=1)cout<<"in"<<endl;
//                else cout<<"out"<<endl;
//            }
//            cout<<"FINISH"<<endl;
//        }
//        else                               //��ջ��Ϊ�գ�˵�����г������ڳ�վ�У��϶�����ʵ����Ŀ�����ĳ�վ����
//        {
//            cout<<"No."<<endl;
//            cout<<"FINISH"<<endl;
//        }
//    }
//    return 0;
//}

