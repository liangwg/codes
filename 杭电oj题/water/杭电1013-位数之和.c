#include<stdio.h>
int len();
int root();
int seat[10000];
int main()
{
	int i,lengh, num=0;  
	char string[100000]={'\0'};   //�洢���� 
	gets(string);
	
	for(i=0;string[i];i++){    //ʵ�ֶԴ�����һ��λ��������㣬�ӳ����ı��ǿ��Դ������ 
		num=num+(string[i]-'0'); 
	}
	//scanf("%d",&num);         //û�п��Ǵ����� 
	while(num!=0){
		lengh=len(num);
		printf("%d\n",root(num,lengh));
	//	scanf("%d",&num);
	    for(i=0;i<100000;i++)
	          string[i]='\0';//��մ洢���������飬�洢��һ�δ��� 
	    gets(string);
	    num=0;
	    for(i=0;string[i];i++)
	        num=num+(string[i]-'0'); 
    }
        return 0;
 } 
 
 int len( int num)    //����λ�� 
 {
 	int i=0;
 	while(num!=0){
 		i++;
 		num=num/10;
	 }
	 return i;
 }
 
 int root(int num,int lengh)  //���������ݹ鷨 
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
 
 
 //����ע����������룬Ӧ���ַ��������洢������Ȼ����λ����ӣ������Ŀ�����Ϊ���������α���int����������
 //�õݹ鷨������������ 
