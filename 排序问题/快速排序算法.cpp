#include<iostream>

using namespace std;
void  quicksort(int, int);
int a[1000];
int main()
{
	int i, n;
	cin >> n;
	for (i = 1; i<=n; i++)
		cin >> a[i];
	

	quicksort(1, n);
	for (i = 1; i<=n; i++)
		cout << a[i];
	return 0;


}
void  quicksort(int left, int right)
{

	int i, j, temp, t;
	 
	//�ݹ����ֹ���������߽�
	if (left > right)   
		return ;

	temp = a[left];  //��׼ֵ��������Ϊ�Ƚϵ�ֵ
	i = left;
	j = right;

	while (i != j)
	{
		 //˳�����Ҫ��Ҫ�����ұߺ���ߣ���Ϊ��׼ֵѡ�ľ�������ߵ�
		while (a[j] >= temp&&j > i)
			j--;          //���ڱ���ʼ̽ѰС�ڻ�׼ֵ�ĵط�
		while (a[i] <= temp&&j > i)
			i++;           //���ڱ���ʼ̽Ѱ���ڻ�׼ֵ�ĵط�
		//�������������������ڱ�
		if (i < j)

		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];//��׼ֵ��λ
	a[i] = temp;
	
	quicksort(left, j-1);  //�ݹ鴦������ j-1����Ҫ
	quicksort(j+1, right);   //�ݹ鴦���Ұ�ߣ�j+1Ҳ����Ҫ

}