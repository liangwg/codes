//#include<stdio.h>
//int f();
//int main()
//{
//	int A,B,n;
//	scanf("%d %d %d",&A,&B,&n);
//	while(A!=0&&B!=0&&n!=0){
//		printf("%d",f(A,B,n));
//		scanf("%d %d %d",&A,&B,&n);
//	}
//	return 0;
// } 
// int f(int a,int b,int n)
// {
// 	if(n==1||n==2)
// 	   return 1;
// 	else 
// 	   return (a*f(a,b,n-1)+b*f(a,b,n-2))%7;
// 	     
// }
//�����ַ����ᳬ�ڴ�,���������ݺܴ�ʱ,�ݹ���ڴ����ĺܴ� 


// ���ڹ�ʽ f[n] = A * f[n-1] + B * f[n-2]; ����ֻ��7 * 7 = 49 �ֿ��ܣ�
//Ϊʲô��ô˵����Ϊ����f[n-1] ���� f[n-2] ��ȡֵֻ�� 0,1,2,3,4,5,6 ��7������A��B���ǹ̶��ģ�
//���Ծ�ֻ��49�ֿ���ֵ�ˡ��ɸù�ϵʽ��֪ÿһ��ֻ��ǰ�������ϵ��
//���Ե�������������ǰ����ֹ�ѭ���ڳ����ˣ�ע��ѭ���ڲ���һ�����ǿ�ʼ�� 1��1 ��
// ����Ϊһ�����������f[n]ֻ��49�п��ܵĴ𰸣������������е�����������ˣ�
//��ô��Ҳ����50�������в���ѭ���ڡ��ҵ�ѭ���ں󣬾Ϳ������ɽ����
#include <stdio.h>
int main()
{
    int a, b, n;
    int f[51], i, t;
    f[0]=f[1]=1;
    while(scanf("%d%d%d",&a,&b,&n)!= EOF && (a || b || n)) // (a || b || n)���߶�Ϊ��ʱΪ�� 
    {   
        for (i=2;i<51;i++)    //�Ƚ�49������������ 
        {   
            f[i]=(a*f[i-1]+b*f[i - 2])%7;
        }   
        
        for (i=0;i<49;i++)      //�ҵ�ѭ���ڵ��λ�� 
        {   
            if (f[49]==f[i]&&f[50]==f[i+1]) 
            {   
                t=i;  
                break;
            }   
        }   
        printf("%d\n", f[n%49+t-2]);   //ѭ��������� ,���е�����Ϊ�������ʽ�� 
    }   
	
	} 
//	
//	#include <cstring>
//#include <cstdio>
//#include <cstdlib>
//using namespace std;
//
//int rec[60];
//
//int main()
//{
//    int a, b, n;
//    rec[0] = rec[1] = rec[2] = 1;
//    while( scanf( "%d %d %d", &a, &b, &n ), a | b | n )
//    {
//        int beg, end, flag = 0;
//        for( int i = 3; i <= n && !flag; ++i )
//        {
//            rec[i] = ( a * rec[i-1] + b * rec[i-2] ) % 7;
//            for( int j = 2; j <= i - 1; ++j )
//            {
//                if( rec[i] == rec[j] && rec[i-1] == rec[j-1] )
//                {
//                    beg = j, end = i;
//                    flag = 1;
//                    break;
//                }
//            }
//        }
//        if( flag )
//        {
//            printf( "%d\n", rec[beg+(n-end)%(end-beg)] );
//        }
//        else
//            printf( "%d\n", rec[n] );
//    }
//    return 0;
//}

