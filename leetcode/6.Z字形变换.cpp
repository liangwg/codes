/*
1.��һ���ַ�����Z�������гɸ�����������֮���������
	���ж�ȡ�ַ���
2.ʵ��һ�����ַ�������ָ�������任�ĺ���
ʾ����s="PAYPALISHIRING" numRows=3
	P A H N   0 3 6 9 �����
	APLSIIG	
	Y I	R
	���:"PAHGAPLSRNYII" 
ʾ���� s="PAYPALISHIRING" numRows=4
	����� "PINALSIGYAHRPI"
	P     I    N
	A   L S  I G
	Y A   H R
	P     I
---------------------------------------------------------
P   H
A  SI
Y I R
PL  IG
A   N
2.���������ַ����飬һ�������洢Z��ͷ��β��һ�������洢Z�м��б�ߣ�Ȼ����һ�����ɽ������
4.string �е�.substring�ķ���ֵ��string����
5.��vector���͵�������������������һ�������룬��.push_back() 
6.�����������ѧ���ɵ���
7.����������û�бȽϺõĽⷨ 
	����һ�ַ�ʽ�����ö�ά���飬������ʾ�Ĵ洢������ͽ�� 
--------------------------------------------------------------------
*/ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string convert(string s,int numRows);
int main()
{
	int numRows;
	string s;
	cin>>s;
	cin>>numRows;
	cout<<convert(s,numRows);
	return 0;
}

string convert(string s,int numRows)
{
	int len=s.size();
	if(numRows==1||numRows>=len)return s; 
	vector<char>str1,str2;
	int i=0,j,k,n1,n2;
	string out; 
	while(i<len)
	{
		for(j=1;j<=numRows&&i<len;i++,j++)
			str1.push_back(s[i]);
		for(j=1;j<=numRows-2&&i<len;i++,j++)
			str2.push_back(s[i]); 
	}
	int len1=str1.size(),len2=str2.size();
	//---------����������str1��str2����������
	for(i=0;i<len1;i=i+numRows)
		out.push_back(str1[i]); 
	for(i=1;i<=numRows-2;i++)  //��ѭ����ʾҪִ�ж��ٴ� 
	{
		for(j=i,k=numRows-2-i;j<len1||k<len2;j=j+numRows,k=k+numRows-2)
		{
			if(j<len1)
				out.push_back(str1[j]);
			if(k<len2)
				out.push_back(str2[k]);
		}	
	}
	for(i=numRows-1;i<str1.size();i=i+numRows)
		out.push_back(str1[i]);
	
	return out;
	
}

 
