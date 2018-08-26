/*

1.两个二进制字符串，返回他们的和(用二进制表示)
2.输入为非字符串且只包含数字1和0
3.示例：a="11",b="1",   “100” 
	a="1010",b="1011"	"10101"
---------------------------------------- 
1.将二进制串进行翻转，然后相加，进位的话就在后面加1，然后结果再翻转过来
3.对于string类型的字符串反转，使用algorithm中的reverse函数
	string s,reverse(s.begin(),s.end()); 
4.string字符串的赋值
	str.push_back('.')单个字符追加在后面
	str.appand(" -阿拉伯"),一个字符串追加在后面 
	str.assign("dream come true"),重新赋值
	str.insert(16,"!!!");//在指定位置插入字符
5.异或操作 
	位运算的运算分量只能是整形或者字符型数据，位运算把运算对象看作
	 是由二进制组成的位串信息，按位完成指定的运算得到位串信息的结果
	 0^0=1; 相应位的值相同的，结果为 0，不相同的结果为 1。
	 
*/ 

#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
string addBinary(string a,string b);
int main()
{
	string a,b,c;
	char t='1';
	cin>>a;
	cin>>b;
	cout<<addBinary(a,b);
	return 0;
}

string addBinary(string a,string b)
{	
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string sum;
	char a1,b1;
	 int C0=0;
	int len_a=a.size(),len_b=b.size(),i=0,j;
	while(i<len_a||i<len_b)
	{
		a1=(i<len_a)?a[i]:'0';
		b1=(i<len_b)?b[i]:'0';
		
	 	sum.push_back(C0^(a1-'0')^(b1-'0')+'0');
	 	C0=(C0+(a1-'0')+(b1-'0')>=2)?1:0;  //进位 
		i++;
	}
	if(C0!=0)sum.push_back('1');
	reverse(sum.begin(),sum.end());
	return sum; 
	
}
