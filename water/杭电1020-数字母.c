#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//int main()
//{
//	int N, i;
//	int AZ[27], state[27];//AZ[27]�洢������state[27]��ʾ�Ƿ����
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
//			AZ[i] = 0;         //�������
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
//					state[string[i] - 'A'] = 1;   //��֤������δ�ӡ
//
//				}
//			}
//			getchar();
//			N--;//���ٲ�������
//			  printf("\n");
//	}
//		return 0;
//
//}

//��ʼ��Ŀ����ˣ����������AABAAC����ȷ�����뷽ʽ��2AB2AC,����Ӧ����4ABC 
int main()
{
	int N, i,j,sum;
	char string[20000];
	scanf("%d", &N);
	getchar();
	while(N!=0)
	{
		memset(string,0,sizeof(char));//�������
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
			 sum=1;    //�ÿ� 
			 i=j; 
		  }
		  printf("\n"); 
		  N--;
		   
		
	}
	return 0;
 } 
