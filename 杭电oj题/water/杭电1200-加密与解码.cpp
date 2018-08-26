#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	int clo,i,j,row;
    char string[500]={'0'},array[30][30];
	while(1)
	{
		cin>>clo;
		if(clo==0)
		  break;
		cin>>string;
		row=strlen(string)/clo;
		i=1;j=1;
		while(i<=row)
		{
			if(i%2==1)//是奇数行 
			{
				if(j<i*clo)
				{
					array[i][j%clo]=string[j-1];
                     j++;
				 } 
				if(j==i*clo)
				{
					array[i][clo]=string[j-1];
					j++;i++;
				}
			}
			else  //偶数行 
			{
				if(j<i*clo)
				{
					array[i][clo+1-j%clo]=string[j-1];j++;
				}
				else
				{
					array[i][1]=string[j-1];i++;j++;
				}
			 } 
		}
		for(j=1;j<=clo;j++)
		{
		  for(i=1;i<=row;i++)
		  {
		  	cout<<array[i][j];
		   }
	    }
		cout<<endl; 
		
	 } 
 } 
