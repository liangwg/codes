//���n��ȫ����������ǽ�n���˿��ƷŽ�n�������� 
#include<iostream>
using namespace std;
void dfs(int);
int times;
int a[100], book[100];  //book[100]�Ǳ�����飬���������Щ���ù���a[100]�Ǻ��ӣ�times<=100
int main()
{
	cin >> times;
	dfs(1);
}
void dfs(int step)
{
	int i; 
	if (step == times + 1) //�߽磬������time+1ʱ����һ��ȫ���е����
	{
		for (i = 1; i <=times; i++) //ע��һ��a[0]λ�ò��洢��step�Ǵ�1��ʼ
			cout << a[i] << "  ";
		cout << endl;
		return;

	}
	int j;
	//��ʱ��վ�ڵ�step������ǰ�棬��1~times����һһ���ԣ����Ի���ѭ��
	for (j = 1; j <= times; j++)
	{
		if (book[j] == 0) //book[i]==0��ʾi���˿��ƻ�������
		{ 
			a[step] = j;  //��j���˿��Ʒ���step�ŵĺ�����
			book[j] = 1;   //��ʾj���˿����Ѿ���������
			dfs(step + 1);
			book[j] = 0;  //��Ҫ��һ��������������ջ�

		}
	}

}

//dfs�ı�׼��ʽ
//void dfs(step)
//{
//�жϱ߽�
//����ÿ�ֿ��� {for(i=1;i<=n;i++)}
//{
//	������һ��dfs(step+1) 
//}
// 
//} 
