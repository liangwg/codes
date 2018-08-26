/*
1.给定一个整数数组nums,找到一个具有最大和的连续子数组(子数组中最少包含一个元素)，返回其最大和
2.示例：[-2,1,-3,4,,-1,2,1,-5,4]     6
3.若你已经实现了复杂度为O(n)的解法，尝试使用更为精妙的分治算法进行求解 
---------------------------------------------------- 
1.动态规划的最大子段和问题 
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
