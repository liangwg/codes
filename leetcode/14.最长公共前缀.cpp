/*
1.查找字符串数组的最长公共前缀，不存在则返回""
2.示例：[flower,flow,flight]
		fl;
		[dog,racecar,car]
		""
-------------------------------------- 
1.很简单，就是一个个的去找
2.注意某些极端情况 

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
