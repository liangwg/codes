/*1.�ַ���ת����
    2.���ҵ���һ���ǿ��ַ�֮ǰ����Ҫ�Ƴ��ַ����еĿո��ַ�(����)
    3.��һ���ǿ��ַ������������ţ����֣���֮��˳�ӳ�������ת��������һ���������ģ�
    4.��һ���ǿ��ַ����в�����Ч���������ַ���Ϊ�գ����ַ������������հ��ַ���������ת��������0
    5.����ֻ��32λ��Ч������������ֵ��Χ��[-2^31,2^31-1],����ֵ�����ɱ�ʾ�ķ�Χ,�򷵻�INT_MAX(2^31-1)��INT_MIN(-2^31)
    6.���԰�����"42"->42,   
            "    -42"->-42, 
            "4193 with words"->4193
            "words and 987"->0
            "-91283472332"->INT_MIN(-2^31)=-2147483648
----------------------------------------------------------
1.�洢��ʽ����char[]�洢��ת����Ĵ洢:��long int �ʹ洢�����
2.�ж��������ȱ�������������һ������Ҫ����ַ�ʱ������ת��ģʽ����֮���򷵻�0
3.����ת��ģʽ����long int�ʹ洢ת�����������������Χ��������Ǵ��ڻ���С�������ض�Ӧ��ֵ
------------------------------------------------------------------------
1.string ��������ô��û�пո���пո� ,�������ͦ���ص� 
	����string���������⣬����cin�����⣬cin���յ��ո�Ͷ������� 
2.string������=���и�ֵ��������==�����еȲ�������+���������� 
3.c����c++�У�scanf()��cin�����ڽ��յ��ո��ʱ�������Ҫ����洢�ո�Ҫ��gets(�ַ�����)
4.Ҫ�ÿո�洢��string �����Ҫ����gets(char[])��Ȼ��string=char[] 
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
	if(len==0)return 0;   //�ַ���Ϊ�� 
	for(i=0;i<len;i++)
	{
		if(str[i]!=' ')
			if(str[i]=='-'||str[i]=='+'||(str[i]>='0'&&str[i]<='9'))
				break;
			else
				return 0;
	}
	if(i==len)//ȫ�ǿո�� 
		return 0;
	//ģʽ�б�
	flag=(str[i]=='-')?-1:1;  //����󷨺� 
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


