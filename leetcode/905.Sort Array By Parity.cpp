/*
1.����һ������A���Ǹ�������������һ��������ż����ǰ�������ں������
2.ʾ����[3,1,2,4]
	�����[2,4,3,1]
3.ע�⣬A�Ĵ�С����1��5000֮�䣬A[i]����0~5000֮�� 
-------------------------------------- 
1.����ԭ�ط�ת�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(n^2),�±�,j,i��
2.ͨ�������ռ临�Ӷ�������ʱ�临�Ӷȣ�������������ֱ�洢������ż����Ȼ�����ӵ�һ��ż����ǰ�������ں�
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
	for(i=0;i<len&&A[i]%2==0;i++);//�ҵ���һ������ 
	while(i<len)
	{
		for(j=i+1;j<len&&A[j]%2!=0;j++);//�ҵ��������ĵ�һ��ż��
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

 
