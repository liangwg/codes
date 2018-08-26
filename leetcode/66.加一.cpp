/*
1.整数组成的非空数组所表示的非负整数，在该数的基础上加1
2.最高位数存放在数组的首位，数组中每个元素只存储一个数字
3.除了整数0以外，这个整数不会以0开头 
4.示例：[1,2,3]		[1,2,4]
		[4,3,2,1]	[4,3,2,2] 
------------------------- 
1.用排除法可以有效地提高筛选效率，先从后往前找到不是9所在的位置
	然后加一，后面的都变成0，若都是9，则重新申请，变成100000... 
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
	for(i=len-1;i>=0&&digits[i]==9;i--);  //判断9所在的位置 
	if(i!=-1)  //不全是9 
	{
		digits[i]++;
		for(j=i+1;j<len;j++)
			digits[j]=0;
		return digits;
	} 
	//全是9的话
	vector<int> nums(len+1);
	nums[0]=1;
	for(i=1;i<=len;i++)
		nums[i]=0;
	return nums;  
 }
