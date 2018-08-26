#include<iostream>
using namespace std;
bool isPalindrome(int x);
int main()
{
	int x;
	cin>>x;
	return (isPalindrome(x)==true)? 1:0;
 } 
 
  bool isPalindrome(int x) {
        if(x<0)return false;
        int seat[100],end=1,i=2,num=x;
        while(num/10!=0)
        {
            seat[end++]=num%10;
            num=num/10;
        }
        seat[end]=num;
        num=seat[1];
        while(i<=end)
        {
            num=num*10+seat[i++];
        }
        
        if(num==x)return true;
        else    return false;
        
    }
