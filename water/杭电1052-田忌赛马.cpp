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
//�൱�� 
//while (cin >> k) { 
//    n = k; 
//    if (n == 0) 
//    break;
//}
//cin>>n,n��һ�����ű��ʽ��ֵ����n��ֵ
//�����˼·���ǰ�������������������ȣ�����ʤ֮����ȵ���������ʤ�����ٰ���ɵ���õ�������������
//������ʤ֮����ʤ֮�������ܣ����ٰ������ƥ����������ĺ���ȣ�������С�ں������֮���������ľ�����Դ��

//������������ɵ�������Ӧ���Ǿ�������֮ǰ�Լ����㷨ֻ��������ΰѾ����������ĵ�����û��ʵ����ɵĳ��ο���
//̰��̰����������ܻ�ʤ����󳡴κ�ʹ��ɵĲ���õ���Դ��������� 
// 
  
