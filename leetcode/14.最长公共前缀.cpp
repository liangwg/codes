/*
1.�����ַ�������������ǰ׺���������򷵻�""
2.ʾ����[flower,flow,flight]
		fl;
		[dog,racecar,car]
		""
-------------------------------------- 
1.�ܼ򵥣�����һ������ȥ��
2.ע��ĳЩ������� 

*/ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs);
int main()
{
	int len;
	cin>>len;
	vector<string>strs(len);
	for(int i=0;i<len;i++)
		cin>>strs[i];
	cout<<longestCommonPrefix(strs);
	return 0; 
}
string longestCommonPrefix(vector<string>& strs)
{
	int len=strs.size(),i=0,j;
	string common="";
	if(len==0)return common; 
	if(len==1&&strs[0].size()!=0)return strs[0];
	if(len==1&&strs[0].size()==0)return common;

	char ch;
	while(1)
	{
		ch=strs[0][i];
		for(j=1;j<len&&ch==strs[j][i];j++);
		if(j==len)
			common.push_back(ch);
		else
			break;
		i++;
	 } 
	 return common;
}
