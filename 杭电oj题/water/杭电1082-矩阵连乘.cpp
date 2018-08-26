
//这题的收获就是1.学会运用了C++自带的stack库函数 
//2.在写代码时，可以先把思路，接下来要写部分写出来，先把此处的算法弄清楚，接下来的就是翻译的事情了 
//3.对于式子的运算顺序的处理，栈是一个很好的思想 
/*1.声明一个stack
stack<int> s1;
stack<string> s2;

2.stack中的操作
stack<int> s;
s.push(x)      无返回值，将元素x压栈
s.pop();       退栈，无返回值
s.top();        取栈顶元素，返回栈顶元素  ,只取不弹
s.empty();     判断栈是否为空，如果是空，返回1，否则返回0
s.size();      返回栈中元素的个数
在栈中没有提供清空操作的函数，但是可以间接地实现清空栈，
while (!s.empty())
{
	s.pop();
}
*/

#include<iostream>
#include<stack>
#include<cstring> 
#define MAX1 1000
#define MAX2 5000
using namespace std;
#include<stdlib.h>
class Matrix {
public:
	int rows;
	int col;
};

void calculate(char*,Matrix*,char*);
int main()
{
	//正确存储数据
	int T;
	cin >> T;
	Matrix M[MAX1];
	char name[MAX1];
	int i;
	for (i = 1; i <= T; i++)
	{
		cin >> name[i];
		cin >> M[i].rows;
		cin >> M[i].col;
	}
    //存储数据检查
	//计算式的输入和处理
	char str[MAX2];
	while ((cin >> str))
	{
		if (1 == strlen(str))
		{
			cout << "0\n";
		}
		else
		{
			calculate(str, M,name);

		}

	}

	//system("pause");
}
//计算主体函数的编写：设置栈，将str中的一个个变形下，压入栈中，并且遇到“）”则进行弹栈操作
//弹栈时，再建一个栈把它逆过来输出，注意，由于栈是Matrix型的，遇到“（”，则用left.row=-1
//代替进栈
void calculate(char*str, Matrix*M,char*name)
{
	//定义栈，并且将str的相关压入栈中
	stack<Matrix> S1;
	stack<Matrix>  trans_S2;
	Matrix M1, M2;
	Matrix left;   //这个表示左括号
	left.rows = -1;
	left.col = -1;
	int sum=0;
	int i;
	int j;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '(')
		{
		
			
			S1.push(left);
		}
		else if (str[i] == ')')
		{
			//开始具体处理，先弹S1的栈，知道弹到“（”为止，弹进trans_S2里
			Matrix temp = S1.top();
			S1.pop();
			while (temp.rows != -1)
			{
				
				trans_S2.push(temp);
				temp = S1.top();
				S1.pop();
			}
			//将trans_S2栈里的元素一个个弹出，若满足矩阵相乘原则，则将其相乘，若不满足
			//直接结束
			
			M1 = trans_S2.top();
			trans_S2.pop();
			while (!trans_S2.empty())
			{
				M2 = trans_S2.top();
				trans_S2.pop();
				
				if (M1.col == M2.rows)
				{
					sum += M1.col*M1.rows*M2.col;//计算次数
					M1.col = M2.col;
					
				}
				else
				{
					cout << "error\n";
					return;
				}
			}
			//相乘结束后，将结果再压入S1的栈中
			S1.push(M1);
		}
		else
		{
			//如果是字符的话，直接找到对应的位置，压入栈中
			for (j = 1; name[j] != str[i]; j++);
			S1.push(M[j]);
		}
	}
	//最后再判断在S1栈里面的元素情况，可能是只剩一个，弹栈输出即可，可能是剩了好几个，要再
	//计算才行
	if (S1.size() == 1)
	{
		M1 = S1.top();
		S1.pop();
		cout << sum << endl;
		return;
	}
	else
	{
		while (!S1.empty())
		{
			trans_S2.push(S1.top());
			S1.pop();
		}
		M1 = trans_S2.top();
		trans_S2.pop();
		while (!trans_S2.empty())
		{
			M2 = trans_S2.top();
			trans_S2.pop();
			if (M1.col == M2.rows)
			{
				sum += M1.col*M1.rows*M2.col;//计算次数
				M1.col = M2.col;
			}
			else
			{
				cout << "error\n";
				return;
			}


		}
		cout << sum<< endl;
	}
}
