/*
1.给定一个数组nums和一个值val,需要原地移除所有数值等于val的元素，返回移除后数组的新长度
2.不要使用额外的数组空间，原地修改数组，O(1)
3.元素的顺序可以改变，不需要考虑数组中超出新长度后面的元素
4.示例：nums=[3,2,2,3]，val=3，返回长度是2，
		nums=[0,1,2,2,3,0,4,2],val=2,返回的新长度是5,是0,1,3,0,4这五个可以为任意顺序
------------------------------------------------------------------------------------ 
1.设立i,j。i指向要被更新的位置，j对整个数组长度进行遍历，当nums[j]!=val时，执行nums[i++]=nums[j], 
2.注意vector<int> nums(len) ,要指明len动态申请的长度 

*/
#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>&nums,int val);
int main()
{
	int len;
	cin>>len;
	int val;
	cin>>val;
	vector<int> nums(len);
///////////////////////// 
	
	for(int i=0;i<len;i++)
		cin>>nums[i];
	cout<<removeElement(nums,val);
	return 0;
}
int removeElement(vector<int>&nums,int val)
{
	int i=0,j=0,len=nums.size();
	for(j=0;j<len;j++)
	{
		if(nums[j]!=val)
			nums[i++]=nums[j]; 
	 } 
	 return i;
	
}
