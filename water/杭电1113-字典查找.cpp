
 /*
1.这题用map特别方便，先将字典里词条读进来，按照字典序排序，然后设置与之对应的每个词条按照字母排序的序列
  在读入一个乱序字母串后，再按字母升序排列，与字典里对比，将升序相同的词条输出。
  由于map自动对前一个变量升序，所以把词条放在前面，把升序排序串放在后面，构造查找表
 2. string s;  sort (s.begin(),s.end());可以对s字符串进行升序排序 
    若是用char s[100];则sort(s,s+strlen(s));进行升序排序 
	   3.map的用法   定义   map <string ,string > node; 
                   填充记录   node.insert(pair<string,string>(t,s)); //里面的记录自动按主关键字进行升序排序
				    遍历记录  1) 定义遍历量map<string,string>::iterator it;
					          2) 遍历   for(it=node.begin ();it!=node.end();it++) 
                            3)   it->second         it->first
                   查找         .find()函数返回一个迭代器指向键值为key的元素，如果没找到就返回指向map尾部的迭代器。  
                 删除   l_it=maplive.find();   maplive.erase(l_it)
                  基本函数
				  map的基本操作函数：
      C++ Maps是一种关联式容器，包含“关键字/值”对
      begin()          返回指向map头部的迭代器
      clear(）         删除所有元素
      count()          返回指定元素出现的次数
      empty()          如果map为空则返回true
      end()            返回指向map末尾的迭代器
      equal_range()    返回特殊条目的迭代器对
      erase()          删除一个元素
      find()           查找一个元素
      get_allocator()  返回map的配置器
      insert()         插入元素
      key_comp()       返回比较元素key的函数
      lower_bound()    返回键值>=给定元素的第一个位置
      max_size()       返回可以容纳的最大元素个数
      rbegin()         返回一个指向map尾部的逆向迭代器
      rend()           返回一个指向map头部的逆向迭代器
      size()           返回map中元素的个数
      swap()            交换两个map
      upper_bound()     返回键值>给定元素的第一个位置
      value_comp()      返回比较元素value的函数 
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
        sort (s.begin(),s.end());//巧妙 
        node.insert(pair<string,string>(t,s));   //map中的记录是自动按主关键字进行升序排序，所以不用再进行排序 
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
