/*
1.����һ������nums��һ��ֵval,��Ҫԭ���Ƴ�������ֵ����val��Ԫ�أ������Ƴ���������³���
2.��Ҫʹ�ö��������ռ䣬ԭ���޸����飬O(1)
3.Ԫ�ص�˳����Ըı䣬����Ҫ���������г����³��Ⱥ����Ԫ��
4.ʾ����nums=[3,2,2,3]��val=3�����س�����2��
		nums=[0,1,2,2,3,0,4,2],val=2,���ص��³�����5,��0,1,3,0,4���������Ϊ����˳��
------------------------------------------------------------------------------------ 
1.����i,j��iָ��Ҫ�����µ�λ�ã�j���������鳤�Ƚ��б�������nums[j]!=valʱ��ִ��nums[i++]=nums[j], 
2.ע��vector<int> nums(len) ,Ҫָ��len��̬����ĳ��� 

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
