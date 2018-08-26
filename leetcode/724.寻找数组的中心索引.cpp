/*
1.给定一个整数类型的数组，编写一个能够返回数组“中心索引”的方法
2.中心索引的定义：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和
3.若数组不存在中心索引，则返回-1,如果数组有多个中心索引，则应该返回最靠左边的那个
4.nums的长度范围为[0,10000]，任何一个nums[i]将会是一个范围在[-1000,1000]的整数 
5.示例:[1,7,3,6,5,6]            3
		[1,2,3]					-1 
----------------------------------------------------------------
1.vector的用法：1)变量声明：声明一个int型向量以替代一维的数组：vector<int>a==声明一个int 数组a，声明一个二维数组，
							vector<int*>a，同理三维，四维等
				2)具体的用法以及函数调用
					(1) .push_back(num)	在数组的最后添加一个数据num
					(2)	.pop_back(num)		去掉数组的最后一个数据num
					(3)	.at(seat)			得到编号位置seat的数据
					(4)	.begin(空)		得到数组头的指针 (返回指向容器第一个元素的迭代器) 
					(5)	.end(空)			得到数组的最后一个单元+1的指针 (返回指向容器的最后一个元素的迭代器) 
					(6)	.front()		得到数组头的引用,传回第一个数据 
					(7)	.back()			得到数组的最后一个单元的引用 
					(8) .max_size()		得到vector最大可以是多少 
					(9)	.capacity()		当前vector分配的大小 
					(10).size()			当前使用数据的大小 
					(11).clear()		清空当前的vector 
					(12).empty()		判断vector是否为空 
					(13).erase(pos)		删除pos位置的数据 
					(14).erase(beg,end) 删除[beg,end]区间的数据 
					(15).resize(num)	重新设置该容器的大小 
					(16). 
2.vector的求和实现
	头文件的名字<numeric> 
	accumulate(要累加元素的头，要累加元素的尾，累加的初值)
	sum=accumulate(vec.begin(),vec.end(),42); 
-------------------------------------------------------
1.从第二个元素开始，判断其符不符合中心索引的定义，逐个遍历到倒数第二个元素 
2.简化判断的方法:若左边元素的和大于右边元素的和，则结束判断，返回-1	
3.存储和，而不是每次都重新再加一遍,sum_front,sum_later,一开始sum_front=第一个元素,sum_later=后面几个元素的和
	迁移判断,sum_front=sum_front+之前作为中心的值，sum_later=sum_later-新的中心的值，然后两者判等	
4.其他人的思路：中间索引的含义：序列总和-中间索引值=2*左半部分的值			
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
