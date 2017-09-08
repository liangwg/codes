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
	 
	//递归的终止条件，即边界
	if (left > right)   
		return ;

	temp = a[left];  //基准值，即是作为比较的值
	i = left;
	j = right;

	while (i != j)
	{
		 //顺序很重要，要是先右边后左边，因为基准值选的就是最左边的
		while (a[j] >= temp&&j > i)
			j--;          //右哨兵开始探寻小于基准值的地方
		while (a[i] <= temp&&j > i)
			i++;           //左哨兵开始探寻大于基准值的地方
		//交换满足条件的左右哨兵
		if (i < j)

		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];//基准值归位
	a[i] = temp;
	
	quicksort(left, j-1);  //递归处理左半边 j-1很重要
	quicksort(j+1, right);   //递归处理右半边，j+1也很重要

}