#include<stdio.h>
#include<math.h>
#include<string.h> 
void change_to_A();
int main()
{
	int  v,x,w,y,z,i,num[20],len,state=0;   //num�洢ת����Ķ�Ӧ������ 
	char input[20]={'\0'},temp[5],max[5]; //input[]�洢�������ĸ������,max[]�洢����Ķ�Ӧ���Ž�,temp[]�� 
	int target;
	scanf("%d",&target);                                   //����ʱ�Ľ� 
	while(target!=0&&input!="END"){
		state=0;           //	�����һ��ѭ�����µ�Ӱ�� 
		memset(input,0,sizeof(char));
		memset(max,0,sizeof(char));
		memset(temp,0,sizeof(char));
		memset(num,0,sizeof(int));   
		getchar();  //�Ե��ո���� 
		gets(input);
		len=strlen(input);        //��ó��� 
		for(i=0;i<len;i++){    //����ѡ�ַ���ת��Ϊ��Ӧ������ 
			num[i]=(input[i]-'A')+1;
		}
	
		for(v=0;v<len;v++)       //��ٷ� ,�������ޣ��벻�����ŵķ��� 
		    for(w=0;w<len;w++)
			   for(x=0;x<len;x++)
			     for(y=0;y<len;y++) 
			     	for(z=0;z<len;z++)                                               //ע��v,w,x,y,z������� 
			     	if(num[v]-pow(num[w],2.0)+pow(num[x],3.0)-pow(num[y],4.0)+pow(num[z],5.0)==target&&v!=w&&v!=x&&v!=y&&v!=z&&w!=x&&w!=y&&w!=z&&x!=y&&x!=z&&y!=z){
			     		state=1;                    //��ʾ�н� 
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
  
  
 
  
