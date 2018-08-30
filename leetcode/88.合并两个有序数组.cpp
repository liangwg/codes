/*
1.给定两个有序的整数数组nums1和nums2将nums1合并到nums1中，使得nums1成为一个有序数组
2.初始化nums1和nums2的元素数量分布为m和n，
3.假设nums1有足够的空间来保存nums2中的元素
4.示例：nums1=[1,2,3,0,0,0],m=3 ;nums2=[2,5,6],n=3;		[1,2,2,3,5,6]
-------------------------------------- 
1.交换法,原地归并排序 ,若nums1[i]>nums2[j],交换这两个值,i++，j不变；若nums1[i]<nums2[j],i++;  
2.楼上的这位的交换归并不行，如果交换的话，得把每次交换完后的数组再重新排序才行，这样时间复杂度就上来了，还是用牺牲空间的归并排序吧 
3.网上的方法更简单：从大到小进行排序相当于m大小的数组与n大小的数组进行从大到小合并，这样不用额外申请数组 
*/ 
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&nums1,int m,vector<int>& nums2,int n);
void merge1(vector<int>&nums1,int m,vector<int>& nums2,int n);
int main()
 {
 	int m,n,i;
 	cin>>m;
 	cin>>n;
	vector<int>nums1(m+n);
	vector<int>nums2(n);
	for(i=0;i<m;i++)
		cin>>nums1[i];
	for(i=0;i<n;i++)
		cin>>nums2[i];
	merge(nums1,m,nums2,n);
	for(i=0;i<m+n;i++)
		cout<<nums1[i]<<" "; 
 	
 }
 void merge(vector<int>&nums1,int m,vector<int>& nums2,int n)
 {
 	int i,j,k=0;
 	vector<int>copy_nums1(m);
	 for(i=0;i<m;i++)
	 	copy_nums1[i]=nums1[i];
	for(i=0,j=0;i<m&&j<n;)
	{
		if(copy_nums1[i]<nums2[j])
		{
			nums1[k++]=copy_nums1[i++];
		}
		else
			nums1[k++]=nums2[j++];
	 } 
	 if(i==m)
	{
	 	for(;j<n;j++)
	 		nums1[k++]=nums2[j];
	}
	else
	{
		for(;i<m;i++)
			nums1[k++]=copy_nums1[i];
	} 
 } 
 
  void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i = m - 1, j = n - 1, index = m + n - 1;
                   while (i >= 0 && j >= 0)
                   {
                             nums1[index--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
                   }
                   while (j >= 0)
                             nums1[index--] = nums2[j--];

    }
};
