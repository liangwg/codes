
//������ջ����1.ѧ��������C++�Դ���stack�⺯�� 
//2.��д����ʱ�������Ȱ�˼·��������Ҫд����д�������ȰѴ˴����㷨Ū������������ľ��Ƿ���������� 
//3.����ʽ�ӵ�����˳��Ĵ���ջ��һ���ܺõ�˼�� 
/*1.����һ��stack
stack<int> s1;
stack<string> s2;

2.stack�еĲ���
stack<int> s;
s.push(x)      �޷���ֵ����Ԫ��xѹջ
s.pop();       ��ջ���޷���ֵ
s.top();        ȡջ��Ԫ�أ�����ջ��Ԫ��  ,ֻȡ����
s.empty();     �ж�ջ�Ƿ�Ϊ�գ�����ǿգ�����1�����򷵻�0
s.size();      ����ջ��Ԫ�صĸ���
��ջ��û���ṩ��ղ����ĺ��������ǿ��Լ�ӵ�ʵ�����ջ��
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
	//��ȷ�洢����
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
    //�洢���ݼ��
	//����ʽ������ʹ���
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
//�������庯���ı�д������ջ����str�е�һ���������£�ѹ��ջ�У�������������������е�ջ����
//��ջʱ���ٽ�һ��ջ��������������ע�⣬����ջ��Matrix�͵ģ�����������������left.row=-1
//�����ջ
void calculate(char*str, Matrix*M,char*name)
{
	//����ջ�����ҽ�str�����ѹ��ջ��
	stack<Matrix> S1;
	stack<Matrix>  trans_S2;
	Matrix M1, M2;
	Matrix left;   //�����ʾ������
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
			//��ʼ���崦���ȵ�S1��ջ��֪������������Ϊֹ������trans_S2��
			Matrix temp = S1.top();
			S1.pop();
			while (temp.rows != -1)
			{
				
				trans_S2.push(temp);
				temp = S1.top();
				S1.pop();
			}
			//��trans_S2ջ���Ԫ��һ����������������������ԭ��������ˣ���������
			//ֱ�ӽ���
			
			M1 = trans_S2.top();
			trans_S2.pop();
			while (!trans_S2.empty())
			{
				M2 = trans_S2.top();
				trans_S2.pop();
				
				if (M1.col == M2.rows)
				{
					sum += M1.col*M1.rows*M2.col;//�������
					M1.col = M2.col;
					
				}
				else
				{
					cout << "error\n";
					return;
				}
			}
			//��˽����󣬽������ѹ��S1��ջ��
			S1.push(M1);
		}
		else
		{
			//������ַ��Ļ���ֱ���ҵ���Ӧ��λ�ã�ѹ��ջ��
			for (j = 1; name[j] != str[i]; j++);
			S1.push(M[j]);
		}
	}
	//������ж���S1ջ�����Ԫ�������������ֻʣһ������ջ������ɣ�������ʣ�˺ü�����Ҫ��
	//�������
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
				sum += M1.col*M1.rows*M2.col;//�������
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
