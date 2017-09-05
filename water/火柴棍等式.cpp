#include<iostream>
using namespace std;
int func(int);
int main()
{
	int A, B, C, m, sum = 0;//m是火柴的总个数，sum表示总共的方案
		cin >> m;       //m小于等于24，并且拼凑+和=需要用掉4根火柴
	for(A=0;A<=11111;A++)//11111是由于用最大火柴数20个拼出的最大数
		for (B = 0; B <= 11111; B++)
		{
			C = A + B;//k表示等号
			if (func(A) + func(B) + func(C) == m - 4)
			{
				sum++;
				cout << "方案" << sum << "如下：" << endl << A << "+" 
					<< B << "=" << C << endl;
			}
		}
	cout << "共计" << sum << endl;
}
int func(int n)
{
	int num[10] = { 6,2,5,5,4,5,6,3,7,6 };
	int sum=0;//用来计数，n总共花费多少个火柴
	while (n / 10 != 0)
	{
		sum += num[n % 10];
		n = n / 10;
	}
	sum += num[n];
	return sum;

}
