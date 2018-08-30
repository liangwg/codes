/*
1.���������������������nums1��nums2��nums1�ϲ���nums1�У�ʹ��nums1��Ϊһ����������
2.��ʼ��nums1��nums2��Ԫ�������ֲ�Ϊm��n��
3.����nums1���㹻�Ŀռ�������nums2�е�Ԫ��
4.ʾ����nums1=[1,2,3,0,0,0],m=3 ;nums2=[2,5,6],n=3;		[1,2,2,3,5,6]
-------------------------------------- 
1.������,ԭ�ع鲢���� ,��nums1[i]>nums2[j],����������ֵ,i++��j���䣻��nums1[i]<nums2[j],i++;  
2.¥�ϵ���λ�Ľ����鲢���У���������Ļ����ð�ÿ�ν�����������������������У�����ʱ�临�ӶȾ������ˣ������������ռ�Ĺ鲢����� 
3.���ϵķ������򵥣��Ӵ�С���������൱��m��С��������n��С��������дӴ�С�ϲ����������ö����������� 
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
