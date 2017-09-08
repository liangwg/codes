//求解n的全排列问题就是将n个扑克牌放进n个盒子里 
#include<iostream>
using namespace std;
void dfs(int);
int times;
int a[100], book[100];  //book[100]是标记数组，用来标记哪些数用过，a[100]是盒子，times<=100
int main()
{
	cin >> times;
	dfs(1);
}
void dfs(int step)
{
	int i; 
	if (step == times + 1) //边界，当到达time+1时就是一种全排列的情况
	{
		for (i = 1; i <=times; i++) //注意一般a[0]位置不存储；step是从1开始
			cout << a[i] << "  ";
		cout << endl;
		return;

	}
	int j;
	//此时是站在第step个盒子前面，把1~times种牌一一尝试，所以会有循环
	for (j = 1; j <= times; j++)
	{
		if (book[j] == 0) //book[i]==0表示i号扑克牌还在手上
		{ 
			a[step] = j;  //将j号扑克牌放入step号的盒子中
			book[j] = 1;   //表示j号扑克牌已经不在手上
			dfs(step + 1);
			book[j] = 0;  //重要的一步，将放入的牌收回

		}
	}

}

//dfs的标准形式
//void dfs(step)
//{
//判断边界
//尝试每种可能 {for(i=1;i<=n;i++)}
//{
//	继续下一步dfs(step+1) 
//}
// 
//} 
