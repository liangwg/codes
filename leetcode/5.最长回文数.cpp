/*
1.����һ���ַ���s���ҵ�s����Ļ����Ӵ���s����󳤶�Ϊ1000 
2.ʾ����"babad"      "bab"
		"cbbd"		"bb"
------------------------------------------ 
1.˼·һ����һ�ַ����Ǵ�����ִ�����С�ִ����б�����һ����������˳���ҵ��������̷���
2.˼·�������ö�̬�滮�㷨 
 	��̬�滮�㷨��dp[i][j]��ʾi��j���ַ�����dp[i][j]=true��ʾ�ǻ����ַ���������false���ǻ����ַ�����
	��ʼ������dp[i][i]=true,Ȼ����ƥ���ҵ�dp[i][i+1]=true�������һ��������������ʼ�㣬һ����ż�����ӵ���ʼ�� 
	״̬ת�Ʒ��̣�dp[i][j]=true(����s[i]==s[j],��dp[i+1][j-1]=true) 
	https://blog.csdn.net/a498506133/article/details/52573592
3.˼·�����Ƚ���һ�������ÿ����һ����(a)���ͼ������Ѱ����ͬ�ַ����Ӵ�(aaa)��Ȼ���Ը��ִ�Ϊ��׼�������߽�����չ,
	ֱ�������߽磬Ȼ���жϴ˴�Ѱ�ҵĳ��Ⱥ͵�ǰ��󳤶ȵıȽϣ�����i=j����aaab����b���Ž������ƵĲ�������ʱ��
	���Ӷ������o(n),���o(n^2) 
	https://blog.csdn.net/ax478/article/details/79810390
4..����������int dp[1000][1000]�������ᳬ������������ ,��������bool dp[1000][1000]  
 
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
//���ö�̬�滮�㷨�������
string longestPalindrome2(string s)
{
	bool dp[1000][1000]={false}; 
	int i,j,end,length=s.size(),step=0,maxlength=0,start=0;
	if(length==1)return s;
	if(length==0)return "";
	//��ʼ��dp���� 
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
	 //״̬ת�Ʒ���
	 for(step=3;step<=length;step++)
	 {
	 	for(i=0;i<=length-step;i++)   //��֤end<length,�õ�i+step-1<length,�õ�i<=length-step 
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
 
