//1ע����ĿҪ����Ŀ��Ҫ��������START������һ���ַ�����������ENDʱ������������������������û������END����� 
//  ������
  //2�������STARTʱ���ǲ�ִ�в�����
  //3ˮ�⣬ϸ�ĵ������  
#include<iostream>
#include<cstring>
using namespace std;
char decode(char);
int main()
{
	//��ȡ
	 char a[205]={'\0'}, b[205]={'\0'};
	int i;
	while(gets(a)) 
	{
		
		if(strcmp(a,"START")==0)
		{
		    memset(a,0,sizeof(a));
		   memset(b,0,sizeof(b));
	    }
		if(strcmp(a,"END")==0)
		   cout<<b<<endl;
		 if(strcmp(a,"ENDOFINPUT")==0)
		      break;
		for(i=0;a[i];i++)
		{
			b[i]=decode(a[i]);
		 }
		 //getchar();  
		 
	}
	 
 } 
 char decode(char ch)
 {
 	if(ch>'Z'||ch<'A')
 	{
 		return ch;
	 }
	 if(ch>='A'&&ch<'F') //ע��������С��F�����ǵ��ں� 
	 {
	 	return ch+21;
	 }
	 else
	 {
	 	return ch-5;
	 }
 }
