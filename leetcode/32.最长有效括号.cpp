/*
1.����һ��ֻ����'('��')'���ַ���,�ҳ���İ�����Ч���ŵ��Ӵ��ĳ���
2.ʾ��:"(()"            2    ()
		")()())"		4	()()
		
----------------------------------------------- 
1.�öѵķ�ʽ�����ѳ������2��
2.�Լ���Ŀû���壬��Ŀ��˼���������Ч���ŵ��Ӵ��ĳ��ȣ�ֻ����һ��������˵һ�Ϸ��ͼ���ȥ
	���� "()(()"����ȷ��Ӧ����2��������4
	()(()  ())()
	һ�����ֲ�ƥ�䣬�����̱Ƚϲ�ƥ�䴦���ߵĳ��ȺͲ�ƥ�䴦֮ǰ���ߵĳ��ȣ�����ȡ���ֵ��Ȼ���ڼ������±��� 
3.¥����λ���ְ취Ҫ���ǵ�����е�డ���������±��־�����б�ǣ�Ȼ��ͳ�����������1�ĸ���.
4.��ת�����ٷ����� 

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
	int end=0;//ָ��Ҫ�����ջ���׸�λ��
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
		{                    //��һ��ʼ���ȳ���')'����ǰ��û����֮ƥ���'('����Ͳ������� 
			if(end!=0&&sta[end-1]=='(')
			{ 
				flag[i]=1;
				flag[num_sta[end-1]]=1;
				end--;//��ջ 
			}
				 
		}
		
	 } 
	//����������ͳ�����1�ĳ�����
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
