#include<iostream>
using namespace std;
int func(int);
int main()
{
	int A, B, C, m, sum = 0;//m�ǻ����ܸ�����sum��ʾ�ܹ��ķ���
		cin >> m;       //mС�ڵ���24������ƴ��+��=��Ҫ�õ�4�����
	for(A=0;A<=11111;A++)//11111���������������20��ƴ���������
		for (B = 0; B <= 11111; B++)
		{
			C = A + B;//k��ʾ�Ⱥ�
			if (func(A) + func(B) + func(C) == m - 4)
			{
				sum++;
				cout << "����" << sum << "���£�" << endl << A << "+" 
					<< B << "=" << C << endl;
			}
		}
	cout << "����" << sum << endl;
}
int func(int n)
{
	int num[10] = { 6,2,5,5,4,5,6,3,7,6 };
	int sum=0;//����������n�ܹ����Ѷ��ٸ����
	while (n / 10 != 0)
	{
		sum += num[n % 10];
		n = n / 10;
	}
	sum += num[n];
	return sum;

}
