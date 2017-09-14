//水题，不解释 

#include<iostream>
using namespace std;
int main()
{
	int underpass[3];
	int i=0;
	for(i=0;i<3;i++)
	    cin>>underpass[i];
	int flag=0;
	for(i=0;i<3;i++)
	{
		if(underpass[i]<=168)
		   {
		   	flag=1;
		   	break;
		   }
		
	 }
	 if(flag==0)
	    cout<<"NO CRASH"<<endl;
	  else
	     cout<<"CRASH "<<underpass[i]<<endl;
	return 0;
} 
 
