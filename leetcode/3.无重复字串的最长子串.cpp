#include<iostream>
/*���ڲ�ѯ����,����֪���п��ܵĽ��,������һ����ѯ��,�Կռ任ȡʱ��,ͨ������ֵ���ж����޳��ֹ� 
/*����˼·:ÿ��ѡ����һ����,�뵱ǰ���н��бȽ�,
�粻�ظ�,�������һ��,
���ظ�,��Ƚ�������ֵ�����,�����ظ�λ�ÿ�ʼ����,
����������,����ǰֵ������ֵ���бȽ�,*/
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
		if(j<=end)//�����ظ������,Ҫ������ֵ�Ƚ�
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
/*��һ��˼·:ͨ�������ռ任ȡʱ��,����һ����ѯ��,һ�����ֹ�,�ͱ�ǳ��ֵ�λ��,�ظ����жϱ�׼(�±겻���ڳ�ʼֵ),
һ���ظ�,��ʼλ�þ�ѡ���ظ���
���Ž���ж�:����λ��i�뿪ʼλ�õĲ�ֵ,��max�ıȽ�. 
/*
int  lengthOfLongestSubstring(string s)
{
	 int locs[256]={-1};//�����ַ���һ�γ��ֵ�λ��
       // memset(locs,-1,sizeof(int));
        int idx = -1, max = 0;//idxΪ��ǰ�Ӵ��Ŀ�ʼλ��-1
        for (int i = 0; i < s.size(); i++)
        {
            if (locs[s[i]] > idx)//�����ǰ�ַ����ֹ�����ô��ǰ�Ӵ�����ʼλ��Ϊ����ַ���һ�γ��ֵ�λ��+1
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
