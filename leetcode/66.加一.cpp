/*
1.������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�1
2.���λ��������������λ��������ÿ��Ԫ��ֻ�洢һ������
3.��������0���⣬�������������0��ͷ 
4.ʾ����[1,2,3]		[1,2,4]
		[4,3,2,1]	[4,3,2,2] 
------------------------- 
1.���ų���������Ч�����ɸѡЧ�ʣ��ȴӺ���ǰ�ҵ�����9���ڵ�λ��
	Ȼ���һ������Ķ����0��������9�����������룬���100000... 
*/ 
#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>&digits);
int main()
{
	int len;
	cin>>len;
	vector<int>digits(len);
	int i;
	for(i=0;i<len;i++)
		cin>>digits[i];
	plusOne
	for(i=0;i<len;i++)
		cout<<digits[i];
	
 } 
 vector<int> plusOne(vector<int>&digits)
 {
 	int len=digits.size(),i,j,flag=0;
	for(i=len-1;i>=0&&digits[i]==9;i--);  //�ж�9���ڵ�λ�� 
	if(i!=-1)  //��ȫ��9 
	{
		digits[i]++;
		for(j=i+1;j<len;j++)
			digits[j]=0;
		return digits;
	} 
	//ȫ��9�Ļ�
	vector<int> nums(len+1);
	nums[0]=1;
	for(i=1;i<=len;i++)
		nums[i]=0;
	return nums;  
 }
