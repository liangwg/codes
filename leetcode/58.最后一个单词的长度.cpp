/*
1.��������Сд��ĸ�Ϳո���ַ��������������һ�����ʵĳ���
2.���������һ�����ʣ�����0
3.ʾ��:Hello World  5 
-----------------------------------------
1.string���÷�
	1)����
		string s;//����һ��string����
		string ss[10];//����һ��string ���������
	2)��ʼ��
		string s1("ssss");
		string s3=s1;
	3)�ַ�������
		(1)substr	s2=s.substr(pos1,n)�����ַ���λ��Ϊpos1�����n���ַ���ɵ��ַ���
					s.substr(pos)�õ�һ��pos����β�Ĵ�
		(2)insert	str.insert(pos,str)//��s��posλ�ò���str
	4)���Һ���
				(1) �����������е�һ�γ��ֵ�λ�ã����û���ҵ��򷵻�string::npos 
					int find(char c,pos);//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ�� 
					int find(char*s,pos);//��pos��ʼ�����ַ���s�ڵ�ǰ����λ��
					int find(string s,pos);//��pos��ʼ�����ַ���s�ڵ�ǰ�ַ�����λ��
				(2) 
					int rfind(char c,pos);//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
					int rfind(char*s,pos);//
					int rfind(char*s,pos,int n=npos);//��pos��ʼ�Ӻ���ǰ�����ַ���s��ǰn���ַ���ɵ��ַ����ڵ�ǰ���е�λ��
						�ɹ��򷵻�����λ��,ʧ���򷵻�string::npos��ֵ 
-----------------------------------------------------------------
1.����˼·������Ҫ����ֻ��һ�����ʵ��������ʱ�������ж�if(s.rfind(' ',0)==string::npos)���������������
	Ȼ�������ڿո���Ҫ�������һ���ո��λ�ã��Ӹ�λ���𣬲��������� 
*/
#include<iostream>
#include<cstring>
using namespace std;
int lengthOfLastWord(string s); 
int main()
{
	char temp[2000];
	gets(temp);
	string s=temp;
	cout<<lengthOfLastWord(s);
	return 0;
	
	
}

int lengthOfLastWord(string s)
{
	int len=s.size();
	if(len==0)return 0;
	if(s.rfind(' ',len-1)==string::npos)return len;
	int i=s.rfind(' ',len-1);
	if(i!=len-1)	 
		return (len-1)-i;
	int sum=0;
	while(s[i]==' ')i--;  //�ҵ��Ǹ��ٽ��ո�ĵ��� 
	for(;i>=0&&s[i]!=' ';i--,sum++);
		return sum;
}
