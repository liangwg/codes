//1注意题目要求，题目是要你输入完START后，输入一串字符，当再输入END时，将解码后的语句输出，而不是没输入完END就输出 
//  解码结果
  //2在输入非START时，是不执行操作的
  //3水题，细心点就行了  
#include<iostream>
#include<cstring>
using namespace std;
char decode(char);
int main()
{
	//读取
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
	 if(ch>='A'&&ch<'F') //注意这里是小于F，不是等于号 
	 {
	 	return ch+21;
	 }
	 else
	 {
	 	return ch-5;
	 }
 }
