/*
1.计算并返回x的平方根，其中x是非负整数
2.返回类型是整数，结果只保留整数部分，小数部分将被舍去
3.示例：4  2
		8  2 
----------------------------------------
1.二分法求平方根函数
	0~x->(left,right)，不断分区间，取中间值mid=left+(right-left)/2
		然后比较是否(x/mid>=mid)是的话，left=mid+1,不是的话，right=mid;
		最后返回right-1; 
*/ 
#include<iostream>
#include<cmath>
using namespace std;
int mySqrt(int x);
int mySqrt2(int);
int main()
{
	int x;
	cin>>x;
	cout<<mySqrt(x);
	return 0;
 } 
int mySqrt(int x)
{
		double qx=sqrt(x);
		return  (int)qx;
	
}
int mySqrt2(int x) {
        if(x<=1) return x;
        int left=0,right=x;
        while(left<right){
            int mid=left+(right-left)/2;
            if(x/mid>=mid) left=mid+1;
            else right=mid;
        }
        return right-1;
    }

