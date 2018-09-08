/*
1.将一个字符串以Z字形排列成给定的行数，之后从左往右
	逐行读取字符，
2.实现一个将字符串进行指定行数变换的函数
示例：s="PAYPALISHIRING" numRows=3
	P A H N   0 3 6 9 间隔是
	APLSIIG	
	Y I	R
	输出:"PAHGAPLSRNYII" 
示例： s="PAYPALISHIRING" numRows=4
	输出： "PINALSIGYAHRPI"
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
2.申请两个字符数组，一个用来存储Z的头和尾，一类用来存储Z中间的斜线，然后按照一定规律进行输出
4.string 中的.substring的返回值是string类型
5.往vector类型的数组里面填数，若是一个个输入，用.push_back() 
6.这题就是找数学规律的题
7.网上搜搜有没有比较好的解法 
	还有一种方式是设置二维数组，形象显示的存储这个解释结果 
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
	//---------接下来处理str1和str2这两个数组
	for(i=0;i<len1;i=i+numRows)
		out.push_back(str1[i]); 
	for(i=1;i<=numRows-2;i++)  //外循环表示要执行多少次 
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

 
