#include<iostream>
#include<cstring>

using namespace std;
int ruler1(char[]);
int ruler2(char[]);
int ruler3(char[]);
int judge_yuan(char);
int main()
{
	 char code[22]={'\0'};
	 cin>>code;
	 while(strcmp(code,"end"))
	 {
	
	 	int judge=ruler1(code)+ruler2(code)+ruler3(code);
	 	if(judge==3)
	 	    cout<<"<"<<code<<"> is acceptable."<<endl;
	 	else
	 	   cout<<"<"<<code<<"> is not acceptable."<<endl;
	 	int i;
	 	for(i=0;code[i];i++)  //清空 
	 	   code[i]='\0';
	 	cin>>code;
	 }
	
 }
 int ruler1(char code[])
 {
 	int i;
     for(i=0;code[i];i++)
    {
	   if(judge_yuan(code[i]))
 	        return 1;
    }
 	    return 0; 
}

int judge_yuan(char a)
{
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	     return 1;
     else
        return 0;
 } 
 
 int ruler2(char code[])
 {
 	int i;
 	for(i=1;code[i];i++)
 	{
 		if(code[i]==code[i-1]&&code[i]!='e'&&code[i]!='o')
 		      return 0;	
	 }
	 return 1;
 }
 int ruler3(char code[])
 {
 	int head=0,tail=1;
 	int i;
 	while((tail-head)<=2&&code[tail])
 	{
 		if(judge_yuan(code[head])==judge_yuan(code[tail]))
 		  {      tail++;
 	      }
 		else
 		     {
 		     	head=tail;
 		     	tail++;
			  }
	 }
	 
	 if(tail-head==3)                //注意这里的判断条件，很容易弄错 
	    return 0;
	else
	   return 1;
 }
