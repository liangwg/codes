#include<iostream>
using namespace std;
int main()
{
	//��֪���������ĺ������������� 
	int T,x,y,sum,dif;
	cin>>T;
	while(T>=1)
	{
		//�������
		cin>>sum;
		cin>>dif;
		if((sum+dif)%2==0&&(sum>=dif)&&(sum-dif)%2==0)  //�ж��Ƿ����Ҫ�� 
		{
			x=(sum+dif)/2;
			y=(sum-dif)/2;
			cout<<x<<" "<<y<<endl; 
		 } 
		 else
		 {
		 	cout<<"impossible\n";
		 }
		T--;
	}
	 
 } 
