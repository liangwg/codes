/*
1.给定一个只包含'('和')'的字符串,找出最长的包含有效括号的子串的长度
2.示例:"(()"            2    ()
		")()())"		4	()()
		
----------------------------------------------- 
1.用堆的方式，进堆出堆则加2，
2.自己题目没看清，题目意思是最长包含有效括号的子串的长度，只能有一个，不是说一合法就加上去
	比如 "()(()"，正确答案应该是2，而不是4
	()(()  ())()
	一旦出现不匹配，就立刻比较不匹配处所走的长度和不匹配处之前所走的长度，两者取最大值，然后在继续往下遍历 
3.楼上这位这种办法要考虑的情况有点多啊，不如用下标标志法进行标记，然后统计最长的连续的1的个数.
4.先转换，再分析法 

*/ 

#include<iostream>
#include<vector>
using namespace std;
int longestValidParentheses(string s);
int main()
{
	string s;
	cin>>s;
	cout<<longestValidParentheses(s);
	return 0;
	
}
int longestValidParentheses(string s)
{
	char sta[100000];
	int num_sta[100000];
	int end=0;//指向将要填入的栈的首个位置
	int len=s.size(),i;
	vector<int> flag(len);
	for(i=0;i<len;i++)
		flag[i]=0; 
//	if(len==0)return 0;

	for(i=0;i<len;i++)
	{
		if(s[i]=='(')
		{
			sta[end]='(';
			num_sta[end]=i;
			end++;
		}
		else
		{                    //若一开始就先出现')'且其前面没有与之匹配的'('，则就不做处理。 
			if(end!=0&&sta[end-1]=='(')
			{ 
				flag[i]=1;
				flag[num_sta[end-1]]=1;
				end--;//弹栈 
			}
				 
		}
		
	 } 
	//接下来就是统计最长的1的长度了
	int sum=0,best=0;
	for(i=0;i<len;i++)
	{
		if(flag[i]==1)
			sum++;
		else
		{
			best=(sum>best)?sum:best;
			sum=0; 
		} 
	 } 
	best=(sum>best)?sum:best;
	 return best;
	 
}
