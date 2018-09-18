/*
1.给定一个字符串s，找到s中最长的回文子串。s的最大长度为1000 
2.示例："babad"      "bab"
		"cbbd"		"bb"
------------------------------------------ 
1.思路一：有一种方法是从最大字串到最小字串进行遍历，一旦按照这种顺序找到，则立刻返回
2.思路二：利用动态规划算法 
 	动态规划算法：dp[i][j]表示i到j的字符串，dp[i][j]=true表示是回文字符串，等于false则不是回文字符串，
	初始条件：dp[i][i]=true,然后再匹配找到dp[i][i+1]=true的情况，一个是奇数增加起始点，一个是偶数增加的起始点 
	状态转移方程：dp[i][j]=true(仅当s[i]==s[j],且dp[i+1][j-1]=true) 
	https://blog.csdn.net/a498506133/article/details/52573592
3.思路三：先进行一层遍历，每遍历一个点(a)，就继续向后寻找相同字符的子串(aaa)，然后以该字串为基准，向两边进行扩展,
	直到遇到边界，然后判断此次寻找的长度和当前最大长度的比较，接着i=j，如aaab，从b接着进行类似的操作。此时间
	复杂度最好是o(n),最坏是o(n^2) 
	https://blog.csdn.net/ax478/article/details/79810390
4..不可以申请int dp[1000][1000]，这样会超过，不能运行 ,可以申请bool dp[1000][1000]  
 
*/  
#include<iostream>
#include<cstring>
using namespace std;
//string longestPalindrome(string s);
string longestPalindrome2(string s);
bool judge(string s);
int main()
{
	string s;
	cin>>s;
	
	//cout<<longestPalindrome(s);
	cout<<longestPalindrome2(s);
	return 0;
	
 } 
 /*
string longestPalindrome(string s)
{
	int len=s.size();
	if(len==1)return s;
	int i,j,k,step;
	string sub;
	for(step=len;step>1;step--)
	{
		for(i=0,j=step-1;j<=len-1;i++,j++)
		{
			sub.clear();
			sub=s.substr(i,j-i+1);
			if(judge(sub))return sub;
			
		}
		
	}
	sub.clear(); 
	sub.push_back(s[0]);
	return sub;
}
bool judge(string s)
{
	int len=s.size(),i,j;
	if(len==1)return true;
	for(i=0,j=len-1;i<j&&s[i]==s[j];i++,j--);
	if(i<j)return false;
	else	return true; 
 } 
 */
//利用动态规划算法进行求解
string longestPalindrome2(string s)
{
	bool dp[1000][1000]={false}; 
	int i,j,end,length=s.size(),step=0,maxlength=0,start=0;
	if(length==1)return s;
	if(length==0)return "";
	//初始化dp数组 
	for(i=0;i<length;i++)
	{
		dp[i][i]=true;
		if(i<length-1&&s.at(i)==s.at(i+1))
		{
			dp[i][i+1]=true;
			maxlength=2;
			start=i;
		}
	 } 
	 //状态转移方程
	 for(step=3;step<=length;step++)
	 {
	 	for(i=0;i<=length-step;i++)   //保证end<length,得到i+step-1<length,得到i<=length-step 
	 	{
	 		end=i+step-1;
	 		if(s.at(i)==s.at(end)&&dp[i+1][end-1]==true)
	 			{
	 				dp[i][end]=true;
	 				if(maxlength<step)
	 				{
	 					maxlength=step;
	 					start=i;
	 				}
				 }
		 }
	  }
	  if(maxlength>=2)
	  	return s.substr(start,maxlength);
	return s.substr(0,1);
 } 
 
