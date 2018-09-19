/*
1.n个非负整数a1,a2,...,an,找出两条线，使得它们与x轴共同构成的容器可以容纳
	最多的水
2.示例：[1,8,6,2,5,4,8,3,7]
	输出49 
------------------------------------------------
1.方法一：二重循环，把所有情况都遍历一遍
2.方法二：利用最小夹板原则，距离减小的同时，只有高夹板才有可能超过它，
	最左最右的两个夹板，要让小的夹板继续往中间移，因为较小的夹板与其他夹板再搭配，也不可能超过现在两个夹板所形成的容量 
3.学会分析问题，假如人去做的话，应该会怎么取巧的去做。 

*/
#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height);
int main()
{
	int len;
	cin>>len;
	vector<int> height(len);
	for(int i=0;i<len;i++)
		cin>>height[i];
	cout<<maxArea(height);
	return 0;
	
 } 
int maxArea(vector<int>& height)
{/* 
	int len=height.size();
	if(len==1||len==0)return 0;
	int i,j,max=0,total=0,temp;
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			temp=(height[i]>height[j])?height[j]:height[i];
			total=temp*(j-i);
			max=(total>max)?total:max;
		}
	}
	return max;
	*/
	 int temp = 0, left = 0, right = height.size()-1;
        while (left < right) {
            temp= max(temp, min(height[left], height[right]) * (right-left));
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }
        
        return temp; 
	
}
