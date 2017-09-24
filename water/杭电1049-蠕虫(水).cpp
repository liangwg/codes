#include<iostream>
using namespace std;
int main()
{
	int height,v,rest;
	while(1)
	{
		cin>>height>>v>>rest;
		if(height==0)
	      break;
	    if(height<=v)
		  cout<<1<<endl;
		else
		{
			int sum=1;
			while(sum*(v-rest)<height-v)
			   sum++;
			cout<<sum*2+1<<endl;
		 } 
		
			
	 } 
}
