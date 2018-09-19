/*
1.n���Ǹ�����a1,a2,...,an,�ҳ������ߣ�ʹ��������x�Ṳͬ���ɵ�������������
	����ˮ
2.ʾ����[1,8,6,2,5,4,8,3,7]
	���49 
------------------------------------------------
1.����һ������ѭ�������������������һ��
2.��������������С�а�ԭ�򣬾����С��ͬʱ��ֻ�и߼а���п��ܳ�������
	�������ҵ������а壬Ҫ��С�ļа�������м��ƣ���Ϊ��С�ļа��������а��ٴ��䣬Ҳ�����ܳ������������а����γɵ����� 
3.ѧ��������⣬������ȥ���Ļ���Ӧ�û���ôȡ�ɵ�ȥ���� 

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
