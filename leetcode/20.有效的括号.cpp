#include<iostream>
#include<stack>
#include<string>
//ע�⣺����ƥ���ʱ�򣬾�Ҫ����false�ˣ����ܼ������ж��� 
/*���ý�ջ��ջ�ķ�ʽ*/
using namespace std;
bool isValid(string s);
int main()
{
	string s;
	cin>>s;
	int flag=(isValid(s))?1:0;
	cout<<flag;
	return 0;
}
/*�Լ���д����ջ�Ľṹ*/ 
bool isValid(string s)
{
	char stac[10000]={'\0'};	//ջ 
	int i=1,start=0;  //ָ��ջ���ĵ�һ���յ�λ�� 
	if(s.size()==0) return true;

	stac[start++]=s[0];

	while(i<s.size())
	{
		 if((s[i]==')'||s[i]==']'||s[i]=='}')&&start==0)
        {start=1;break;}
		if(s[i]=='('|| s[i]=='{'||s[i]=='[')
		{
			stac[start++]=s[i];
			i++; 
			continue;
		}
		cout<<start<<endl;
		switch(s[i])
		{
			case ')': 
				if(stac[start-1]=='(')
					start--;
					break;
			case '}':
				if(stac[start-1]=='{')
					start--;
					break;
			case ']':
				if(stac[start-1]=='[')
					start--;
					break;
		}
		i++;
	}
	if(start==0)return true;
	else	return false;	
}
/* 
bool isValid(string s)
{
	 if(s.length()==0)
            return true;
        if(s.length()%2==1)
            return false;
        stack<char> temp;
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                temp.push(s[i]);
            else 
            {
                if(temp.empty())
                    return false;
                if(s[i]==')'&&temp.top()!='(')
                    return false;
                if(s[i]==']'&&temp.top()!='[')
                    return false;
                if(s[i]=='}'&&temp.top()!='{')
                    return false;
                temp.pop();
            }
        }
            return temp.empty();
    }
}
*/ 
