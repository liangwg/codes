#include <fstream> 
#include<iostream> 
#include <algorithm>
using namespace std;
int tian[1005],king[1005];
int main(void)
{
   
    int n;
    while(cin>>n,n)
    {
        for(int i=1;i<=n;i++)
        cin>>tian[i];
        for(int i=1;i<=n;i++)
            cin>>king[i];
          int  good1=n;
           int  good2=n;
            int bad1=1;
            int bad2=1;
            int money=0;
            sort(tian+1,tian+n+1);
            sort(king+1,king+n+1);
            
            while(good1>=bad1)
            { 
               if(tian[bad1]>king[bad2])    
               {
                   bad1++;
                   bad2++;
                   money+=200;
                   continue;
               }
               if(tian[good1]>king[good2])
               {
                   good1--;
                   good2--;
                   money+=200;
                   continue;
               }
               if(tian[bad1]<king[good2])
                   money-=200;
                good2--;
                bad1++;
            }
            cout<<money<<endl;

    }

    return 0;
}
// while(cin>>n,n)
//相当于 
//while (cin >> k) { 
//    n = k; 
//    if (n == 0) 
//    break;
//}
//cin>>n,n是一个逗号表达式，值就是n的值
//此题的思路就是把田忌最坏的马与君王最坏的马比，若能胜之，则比掉，若不能胜，则再把田忌的最好的马与君王的马比
//，若能胜之，则胜之，若不能，则再把田忌那匹差马与君王的好马比，若差马小于好马则比之，用以消耗君王资源，

//此题着眼于田忌的马，而不应该是君王的马，之前自己的算法只是想着如何把君王的马消耗掉，而没有实现田忌的场次考虑
//贪心贪的是田忌所能获胜的最大场次和使田忌的差马得到资源的最大化利用 
// 
  
