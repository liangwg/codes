#include<iostream>
#include<cstring>
using namespace std;
string countAndSay(int n);
int main()
{
	int n;
	cin>>n;
	cout<<countAndSay(n);
	return 0;
//	string str;
//	str.append("my name is jiayp");
//	str.append(1,'x');
	//str[0].push_back('1');
//	cout<<str;
}
string countAndSay(int n)
{
	string str[2];
	char ch,count;
	int i,j,k,t=0,s;
	str[0]="1";
	i=0;s=1;
	while(s<n)
	{
		i=0;t=0;
		while(i<str[0].length())
		{
			count='1';
		
			ch=str[0][i];
			for(j=i+1;j<str[0].length()&&ch==str[0][j];j++)
				count++;
			str[1].append(1,count);
			str[1].append(1,ch);
			i=j;
		}
		str[0]=str[1];
		str[1].clear();
		s++;
	}
	return str[0];
}
