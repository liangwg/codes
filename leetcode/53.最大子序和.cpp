/*
1.����һ����������nums,�ҵ�һ���������͵�����������(�����������ٰ���һ��Ԫ��)������������
2.ʾ����[-2,1,-3,4,,-1,2,1,-5,4]     6
3.�����Ѿ�ʵ���˸��Ӷ�ΪO(n)�Ľⷨ������ʹ�ø�Ϊ����ķ����㷨������� 
---------------------------------------------------- 
1.��̬�滮������Ӷκ����� 
*/
#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>&nums);
int main()
{
	int len;
	cin>>len;
	vector<int> nums(len);
	for(int i=0;i<len;i++)
		cin>>nums[i];
	cout<<maxSubArray(nums);
	return 0; 
	
 } 
int maxSubArray(vector<int>&nums)
{
	int len=nums.size();
	if(len==1)return nums[0];
	int	max=-9999999;
	int b=-1;
	for(int i=0;i<len;i++)
	{
		if(b<0)
			b=nums[i]; 
		else
			b+=nums[i];
		if(b>max)
			max=b;
	}
	return max; 
}
