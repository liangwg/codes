/*
1.����һ���������͵����飬��дһ���ܹ��������顰�����������ķ���
2.���������Ķ��壺���������������������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ�
3.�����鲻���������������򷵻�-1,��������ж��������������Ӧ�÷������ߵ��Ǹ�
4.nums�ĳ��ȷ�ΧΪ[0,10000]���κ�һ��nums[i]������һ����Χ��[-1000,1000]������ 
5.ʾ��:[1,7,3,6,5,6]            3
		[1,2,3]					-1 
----------------------------------------------------------------
1.vector���÷���1)��������������һ��int�����������һά�����飺vector<int>a==����һ��int ����a������һ����ά���飬
							vector<int*>a��ͬ����ά����ά��
				2)������÷��Լ���������
					(1) .push_back(num)	�������������һ������num
					(2)	.pop_back(num)		ȥ����������һ������num
					(3)	.at(seat)			�õ����λ��seat������
					(4)	.begin(��)		�õ�����ͷ��ָ�� (����ָ��������һ��Ԫ�صĵ�����) 
					(5)	.end(��)			�õ���������һ����Ԫ+1��ָ�� (����ָ�����������һ��Ԫ�صĵ�����) 
					(6)	.front()		�õ�����ͷ������,���ص�һ������ 
					(7)	.back()			�õ���������һ����Ԫ������ 
					(8) .max_size()		�õ�vector�������Ƕ��� 
					(9)	.capacity()		��ǰvector����Ĵ�С 
					(10).size()			��ǰʹ�����ݵĴ�С 
					(11).clear()		��յ�ǰ��vector 
					(12).empty()		�ж�vector�Ƿ�Ϊ�� 
					(13).erase(pos)		ɾ��posλ�õ����� 
					(14).erase(beg,end) ɾ��[beg,end]��������� 
					(15).resize(num)	�������ø������Ĵ�С 
					(16). 
2.vector�����ʵ��
	ͷ�ļ�������<numeric> 
	accumulate(Ҫ�ۼ�Ԫ�ص�ͷ��Ҫ�ۼ�Ԫ�ص�β���ۼӵĳ�ֵ)
	sum=accumulate(vec.begin(),vec.end(),42); 
-------------------------------------------------------
1.�ӵڶ���Ԫ�ؿ�ʼ���ж�������������������Ķ��壬��������������ڶ���Ԫ�� 
2.���жϵķ���:�����Ԫ�صĺʹ����ұ�Ԫ�صĺͣ�������жϣ�����-1	
3.�洢�ͣ�������ÿ�ζ������ټ�һ��,sum_front,sum_later,һ��ʼsum_front=��һ��Ԫ��,sum_later=���漸��Ԫ�صĺ�
	Ǩ���ж�,sum_front=sum_front+֮ǰ��Ϊ���ĵ�ֵ��sum_later=sum_later-�µ����ĵ�ֵ��Ȼ�������е�	
4.�����˵�˼·���м������ĺ��壺�����ܺ�-�м�����ֵ=2*��벿�ֵ�ֵ			
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int pivotIndex(vector<int>&nums);
int main()
{
	int n;
	cin>>n;
	 
	vector<int>num(n);
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	cout<<pivotIndex(num);
	 
 } 
int pivotIndex(vector<int>&nums)
{
	int len=nums.size();
	if(len==1)return 0;
	if(len==2||len==0)return -1;
	if(accumulate(nums.begin()+1,nums.end(),0)==0)return 0;
	int sum_front=nums[0],sum_later=accumulate(nums.begin()+2,nums.end(),0),i,pivot=1;
	while(pivot<=len-2)
	{
		if(sum_front==sum_later)
			return pivot;
		sum_front+=nums[pivot];
		sum_later-=nums[pivot+1];
		pivot++; 
	}
	if(accumulate(nums.begin(),nums.end()-1,0)==0)return len-1;
	return -1;
}
