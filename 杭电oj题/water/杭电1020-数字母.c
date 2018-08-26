#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//int main()
//{
//	int N, i;
//	int AZ[27], state[27];//AZ[27]存储个数，state[27]表示是否输出
//	char string[20000];
//	scanf("%d", &N);
//	getchar();
//	while (N != 0)
//	{
//		for(i=0;string[i];i++)
//		    string[i]='\0'; 
//		//memset(string, 0, sizeof(char));
//		for (i = 0; i < 27; i++)
//		{
//			AZ[i] = 0;         //清空数组
//			state[i] = 0;
//	    }
//			scanf("%s", string);
//			for (i = 0; string[i]; i++)
//			{
//				AZ[string[i] - 'A']++;
//			}
//			for (i = 0; string[i]; i++)
//			{
//				if (AZ[string[i]-'A']==1)
//					printf("%c", string[i]);
//				else if (AZ[string[i] - 'A'] > 1 && state[string[i] - 'A'] == 0)
//				{
//					printf("%d%c", AZ[string[i]-'A'],string[i]);
//					state[string[i] - 'A'] = 1;   //保证不会二次打印
//
//				}
//			}
//			getchar();
//			N--;//减少测试组数
//			  printf("\n");
//	}
//		return 0;
//
//}

//开始题目审错了，对于输入的AABAAC，正确的输入方式是2AB2AC,而不应该是4ABC 
int main()
{
	int N, i,j,sum;
	char string[20000];
	scanf("%d", &N);
	getchar();
	while(N!=0)
	{
		memset(string,0,sizeof(char));//清空数组
		scanf("%s",string);
		 i=0;
		 sum=1;
		 while(string[i])
		 {
		 	for(j=i+1;string[j]&&string[i]==string[j];j++)
		 	{
		 		sum++;
			 }
			 if(sum==1)
			 {
			 	printf("%c",string[i]);
			 }
			 else
			 {
			 	printf("%d%c",sum,string[i]);
			 }
			 sum=1;    //置空 
			 i=j; 
		  }
		  printf("\n"); 
		  N--;
		   
		
	}
	return 0;
 } 
