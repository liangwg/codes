
 /*
1.������map�ر𷽱㣬�Ƚ��ֵ�������������������ֵ�������Ȼ��������֮��Ӧ��ÿ������������ĸ���������
  �ڶ���һ��������ĸ�����ٰ���ĸ�������У����ֵ���Աȣ���������ͬ�Ĵ��������
  ����map�Զ���ǰһ�������������԰Ѵ�������ǰ�棬���������򴮷��ں��棬������ұ�
 2. string s;  sort (s.begin(),s.end());���Զ�s�ַ��������������� 
    ������char s[100];��sort(s,s+strlen(s));������������ 
	   3.map���÷�   ����   map <string ,string > node; 
                   ����¼   node.insert(pair<string,string>(t,s)); //����ļ�¼�Զ������ؼ��ֽ�����������
				    ������¼  1) ���������map<string,string>::iterator it;
					          2) ����   for(it=node.begin ();it!=node.end();it++) 
                            3)   it->second         it->first
                   ����         .find()��������һ��������ָ���ֵΪkey��Ԫ�أ����û�ҵ��ͷ���ָ��mapβ���ĵ�������  
                 ɾ��   l_it=maplive.find();   maplive.erase(l_it)
                  ��������
				  map�Ļ�������������
      C++ Maps��һ�ֹ���ʽ�������������ؼ���/ֵ����
      begin()          ����ָ��mapͷ���ĵ�����
      clear(��         ɾ������Ԫ��
      count()          ����ָ��Ԫ�س��ֵĴ���
      empty()          ���mapΪ���򷵻�true
      end()            ����ָ��mapĩβ�ĵ�����
      equal_range()    ����������Ŀ�ĵ�������
      erase()          ɾ��һ��Ԫ��
      find()           ����һ��Ԫ��
      get_allocator()  ����map��������
      insert()         ����Ԫ��
      key_comp()       ���رȽ�Ԫ��key�ĺ���
      lower_bound()    ���ؼ�ֵ>=����Ԫ�صĵ�һ��λ��
      max_size()       ���ؿ������ɵ����Ԫ�ظ���
      rbegin()         ����һ��ָ��mapβ�������������
      rend()           ����һ��ָ��mapͷ�������������
      size()           ����map��Ԫ�صĸ���
      swap()            ��������map
      upper_bound()     ���ؼ�ֵ>����Ԫ�صĵ�һ��λ��
      value_comp()      ���رȽ�Ԫ��value�ĺ��� 
	  */          
#include<iostream> 
#include<stdio.h> 
#include<map> 
#include<string> 
#include<algorithm> 
using namespace std; 
map <string ,string > node; 
int main() 
{ 
    string s; 
    while(cin>>s&&s!="XXXXXX") 
    { 
        string t=s; 
        sort (s.begin(),s.end());//���� 
        node.insert(pair<string,string>(t,s));   //map�еļ�¼���Զ������ؼ��ֽ��������������Բ����ٽ������� 
 } 
 while(cin>>s) 
 { 
  if(s=="XXXXXX") break; 
  int flag=1; 
  map<string,string>::iterator it; 
    sort(s.begin (),s.end ()); 
    for(it=node.begin ();it!=node.end();it++) 
    { 
     if(it->second==s) 
     { 
      flag=0;cout<<it->first<<endl; 
     } 
    } 
    if(flag) cout<<"NOT A VALID WORD"<<endl; 
    cout<<"******"<<endl; 
 } 
 return 0; 
}  
