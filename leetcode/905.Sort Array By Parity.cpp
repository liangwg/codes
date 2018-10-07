/*
1.给定一个数组A，非负正整数，返回一个数组由偶数在前，奇数在后的数组
2.示例：[3,1,2,4]
	输出：[2,4,3,1]
3.注意，A的大小介于1到5000之间，A[i]介于0~5000之间 
-------------------------------------- 
1.采用原地翻转法，空间复杂度O(1)，时间复杂度O(n^2),下标,j,i法
2.通过牺牲空间复杂度来降低时间复杂度，申请两个数组分别存储奇数和偶数，然后连接到一起，偶数在前，奇数在后。
		even.insert(even.end(),odd.begin(),odd.end()); 
*/ 
#include<iostream>
#include<vector> 
using namespace std;
vector<int> sortArrayByParity(vector<int>&A);
int main()
{
	int n,i;
	cin>>n;
	vector<int>A(n);
	vector<int>B(n);
	for(i=0;i<n;i++)
		cin>>A[i];
	B=sortArrayByParity(A);
	for(i=0;i<n;i++)
		cout<<B[i];
	return 0; 
}
vector<int> sortArrayByParity(vector<int>&A)
{
	int len=A.size(),i=0,j=0,temp;
	for(i=0;i<len&&A[i]%2==0;i++);//找到第一个奇数 
	while(i<len)
	{
		for(j=i+1;j<len&&A[j]%2!=0;j++);//找到接下来的第一个偶数
	 	if(j<len)
		 {
		 	temp=A[i];
		 	A[i]=A[j];
		 	A[j]=temp;
		  } 
		else
		{
			break;
		}
		if(i==j-1)
			i=j;
		else
			i++;
	    
	}
	return A;
} 

 
