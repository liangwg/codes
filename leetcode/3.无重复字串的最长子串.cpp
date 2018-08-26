#include<iostream>
/*对于查询问题,若已知所有可能的结果,可以设一个查询表,以空间换取时间,通过设置值来判断有无出现过 
/*此题思路:每次选择完一个后,与当前序列进行比较,
如不重复,则继续下一个,
若重复,则比较与最优值的情况,并以重复位置开始搜索,
若搜索结束,将当前值与最优值进行比较,*/
using namespace std;
int lengthOfLongestSubstring(string s);
int main()
{
	string str;
	cin>>str;
	cout<<lengthOfLongestSubstring(str);
}
int  lengthOfLongestSubstring(string str)
{
	int sum=0,i=1,j,len=str.length(),start=0,end=0;
	while(i<len)
	{
		for(j=start;str[i]!=str[j]&&j<=end;j++);
		if(j<=end)//是有重复的情况,要与最优值比较
		{
			sum=(end-start+1>sum)?end-start+1:sum;
			start=j+1;
		}
			end++;
			i++; 
	}
	sum=(end-start+1>sum)?end-start+1:sum;
	return sum;
}
/*另一种思路:通过牺牲空间换取时间,设置一个查询表,一旦出现过,就标记出现的位置,重复的判断标准(下标不等于初始值),
一旦重复,开始位置就选择重复点
最优解的判断:遍历位置i与开始位置的差值,与max的比较. 
/*
int  lengthOfLongestSubstring(string s)
{
	 int locs[256]={-1};//保存字符上一次出现的位置
       // memset(locs,-1,sizeof(int));
        int idx = -1, max = 0;//idx为当前子串的开始位置-1
        for (int i = 0; i < s.size(); i++)
        {
            if (locs[s[i]] > idx)//如果当前字符出现过，那么当前子串的起始位置为这个字符上一次出现的位置+1
            {
                idx = locs[s[i]];
            }
            if (i - idx > max)
            {
               max = i - idx;
            }
            locs[s[i]] = i;
        }
        return max;
}
*/	
