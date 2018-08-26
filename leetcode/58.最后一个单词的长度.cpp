/*
1.仅包含大小写字母和空格的字符串，返回其最后一个单词的长度
2.不存在最后一个单词，返回0
3.示例:Hello World  5 
-----------------------------------------
1.string的用法
	1)声明
		string s;//声明一个string对象
		string ss[10];//声明一个string 对象的数组
	2)初始化
		string s1("ssss");
		string s3=s1;
	3)字符串处理
		(1)substr	s2=s.substr(pos1,n)返回字符串位置为pos1后面的n个字符组成的字符串
					s.substr(pos)得到一个pos到结尾的串
		(2)insert	str.insert(pos,str)//在s的pos位置插入str
	4)查找函数
				(1) 函数返回序列第一次出现的位置，如果没有找到则返回string::npos 
					int find(char c,pos);//从pos开始查找字符c在当前字符串的位置 
					int find(char*s,pos);//从pos开始查找字符串s在当前串的位置
					int find(string s,pos);//从pos开始查找字符串s在当前字符串的位置
				(2) 
					int rfind(char c,pos);//从pos开始查找字符c在当前字符串的位置
					int rfind(char*s,pos);//
					int rfind(char*s,pos,int n=npos);//从pos开始从后向前查找字符串s中前n个字符组成的字符串在当前的中的位置
						成功则返回所在位置,失败则返回string::npos的值 
-----------------------------------------------------------------
1.此题思路：首先要考虑只有一个单词的情况，这时可以用判断if(s.rfind(' ',0)==string::npos)用来考虑这种情况
	然后若存在空格，则要返回最后一个空格的位置，从该位置起，不断向后计数 
*/
#include<iostream>
#include<cstring>
using namespace std;
int lengthOfLastWord(string s); 
int main()
{
	char temp[2000];
	gets(temp);
	string s=temp;
	cout<<lengthOfLastWord(s);
	return 0;
	
	
}

int lengthOfLastWord(string s)
{
	int len=s.size();
	if(len==0)return 0;
	if(s.rfind(' ',len-1)==string::npos)return len;
	int i=s.rfind(' ',len-1);
	if(i!=len-1)	 
		return (len-1)-i;
	int sum=0;
	while(s[i]==' ')i--;  //找到那个临近空格的单词 
	for(;i>=0&&s[i]!=' ';i--,sum++);
		return sum;
}
