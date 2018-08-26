/*
1.���㲢����x��ƽ����������x�ǷǸ�����
2.�������������������ֻ�����������֣�С�����ֽ�����ȥ
3.ʾ����4  2
		8  2 
----------------------------------------
1.���ַ���ƽ��������
	0~x->(left,right)�����Ϸ����䣬ȡ�м�ֵmid=left+(right-left)/2
		Ȼ��Ƚ��Ƿ�(x/mid>=mid)�ǵĻ���left=mid+1,���ǵĻ���right=mid;
		��󷵻�right-1; 
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

