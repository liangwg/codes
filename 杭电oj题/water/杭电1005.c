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
//用这种方法会超内存,当测试数据很大时,递归的内存消耗很大 


// 对于公式 f[n] = A * f[n-1] + B * f[n-2]; 后者只有7 * 7 = 49 种可能，
//为什么这么说，因为对于f[n-1] 或者 f[n-2] 的取值只有 0,1,2,3,4,5,6 这7个数，A，B又是固定的，
//所以就只有49种可能值了。由该关系式得知每一项只与前两项发生关系，
//所以当连续的两项在前面出现过循环节出现了，注意循环节并不一定会是开始的 1，1 。
// 又因为一组测试数据中f[n]只有49中可能的答案，最坏的情况是所有的情况都遇到了，
//那么那也会在50次运算中产生循环节。找到循环节后，就可以轻松解决了
#include <stdio.h>
int main()
{
    int a, b, n;
    int f[51], i, t;
    f[0]=f[1]=1;
    while(scanf("%d%d%d",&a,&b,&n)!= EOF && (a || b || n)) // (a || b || n)三者都为零时为假 
    {   
        for (i=2;i<51;i++)    //先将49种情况计算出来 
        {   
            f[i]=(a*f[i-1]+b*f[i - 2])%7;
        }   
        
        for (i=0;i<49;i++)      //找到循环节点的位置 
        {   
            if (f[49]==f[i]&&f[50]==f[i+1]) 
            {   
                t=i;  
                break;
            }   
        }   
        printf("%d\n", f[n%49+t-2]);   //循环法计算的 ,仍有点困惑，为何是这个式子 
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

