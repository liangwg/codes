/*1.字符串转整数
    2.在找到第一个非空字符之前，需要移出字符串中的空格字符(遍历)
    3.第一个非空字符必须是正负号，数字，且之后顺延长度最大的转换，若第一个是其他的，
    4.第一个非空字符序列不少有效整数，或字符串为空，或字符串仅仅包含空白字符，不进行转换，返回0
    5.环境只是32位有效符号整数，数值范围是[-2^31,2^31-1],若数值超过可表示的范围,则返回INT_MAX(2^31-1)或INT_MIN(-2^31)
    6.测试案例："42"->42,   
            "    -42"->-42, 
            "4193 with words"->4193
            "words and 987"->0
            "-91283472332"->INT_MIN(-2^31)=-2147483648
----------------------------------------------------------
1.存储方式：用char[]存储，转换后的存储:用long int 型存储结果，
2.判断条件，先遍历，当遇到第一个满足要求的字符时，进入转换模式，反之，则返回0
3.进入转换模式后，用long int型存储转换后的数，若超过范围，则根据是大于还是小于来返回对应的值
------------------------------------------------------------------------
1.string 变量该怎么让没有空格的有空格 ,这个问题挺严重的 
	不是string变量的问题，而是cin的问题，cin接收到空格就饿结束了 
2.string变量用=进行赋值操作，用==进行判等操作，用+做串联操作 
3.c或者c++中，scanf()和cin都会在接收到空格的时候接束，要输入存储空格，要用gets(字符数组)
4.要让空格存储在string 数组里，要先用gets(char[])，然后string=char[] 
*/
#include<iostream>
#include<cstring>
using namespace std;

int MyAuto(string str);
int main()
{
    string str;
    char temp[10000];
    gets(temp);
    str=temp;
	cout<<MyAuto(str);
    return 0;
}
int MyAuto(string str)
{
	long long int result=0;
	int min=0x80000000;
	int max=0x7fffffff;
	int i,len=str.length(),flag=1;
	if(len==0)return 0;   //字符串为空 
	for(i=0;i<len;i++)
	{
		if(str[i]!=' ')
			if(str[i]=='-'||str[i]=='+'||(str[i]>='0'&&str[i]<='9'))
				break;
			else
				return 0;
	}
	if(i==len)//全是空格符 
		return 0;
	//模式判别
	flag=(str[i]=='-')?-1:1;  //这个大法好 
	i=(str[i]=='-'||str[i]=='+')?i+1:i;
	while(i<len&&str[i]<='9'&&str[i]>='0')
	{
		result=result*10+(str[i]-'0');
		if(flag==-1)
		{
		//	cout<<result<<endl;
			if(flag*result<min)
				return min;
		}
		else
		{
			if(result>max)
				return max; 
		}
		i++;
	}
	return flag*result;
}


