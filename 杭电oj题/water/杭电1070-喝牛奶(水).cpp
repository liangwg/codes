#include<iostream>
using namespace std;
class Milk{
      public:
             char name[101];
             int price;
             int Vol;
      };
Milk milks[101];
int main()
{
    int T,N;
    cin>>T;
    while(T>=1)
    {
       cin>>N;
       
       int i,min,days; 
       double min_av=9999999,av;
       for(i=1;i<=N;i++)
       {
       	getchar(); 
           cin.getline(milks[i].name,101,' ');
      
           cin>>milks[i].price;
        
           cin>>milks[i].Vol;
      
        }
        min=1;
        for(i=1;i<=N;i++)
        {      
        	if(milks[i].Vol<200)
        	   continue;
        	days=milks[i].Vol/200;
        	if(days>=6)        //不喝大于等于6天的牛奶 
        	     days=5;
        	
			 av=(double)milks[i].price/days;   //计算平均值 
			 if(min_av>=av)
				{
					if(min_av>av)
					{ 
					min=i;
					min_av=av;
				    }
				    if(min_av==av)             //注意审题,当平均价格相同时，就要比较容量了 
				    {
				    	if(milks[min].Vol<milks[i].Vol)
				    	{
				    		min=i;
						} 
					}
				 } 
		}
		cout<<milks[min].name<<endl;
		T--;
                        
    }
    
}      
