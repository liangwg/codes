/*

1.�����������ַ������������ǵĺ�(�ö����Ʊ�ʾ)
2.����Ϊ���ַ�����ֻ��������1��0
3.ʾ����a="11",b="1",   ��100�� 
	a="1010",b="1011"	"10101"
---------------------------------------- 
1.�������ƴ����з�ת��Ȼ����ӣ���λ�Ļ����ں����1��Ȼ�����ٷ�ת����
3.����string���͵��ַ�����ת��ʹ��algorithm�е�reverse����
	string s,reverse(s.begin(),s.end()); 
4.string�ַ����ĸ�ֵ
	str.push_back('.')�����ַ�׷���ں���
	str.appand(" -������"),һ���ַ���׷���ں��� 
	str.assign("dream come true"),���¸�ֵ
	str.insert(16,"!!!");//��ָ��λ�ò����ַ�
5.������ 
	λ������������ֻ�������λ����ַ������ݣ�λ��������������
	 ���ɶ�������ɵ�λ����Ϣ����λ���ָ��������õ�λ����Ϣ�Ľ��
	 0^0=1; ��Ӧλ��ֵ��ͬ�ģ����Ϊ 0������ͬ�Ľ��Ϊ 1��
	 
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
	 	C0=(C0+(a1-'0')+(b1-'0')>=2)?1:0;  //��λ 
		i++;
	}
	if(C0!=0)sum.push_back('1');
	reverse(sum.begin(),sum.end());
	return sum; 
	
}
