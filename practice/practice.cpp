#include <iostream>
using namespace std;

int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 {
   cin>>a[i];
 }
 int m;
 cin>>m;
 int b[m];
 for(int i=0;i<m;i++)
 {
   cin>>b[i];
 }
 int i=0;
 int j=0;
 int first=min(a[0],b[0]);
 int second=max(a[0],b[0]);
 int ans=0;
 
 while(i<n &&j<m)
 {
   
       if(first>second)//context switch hoga.............
       {
        ans++;
        if(first==a[i])
        {
          j++;
          first=b[j];
          second=a[i];
        }
        else
        {
          i++;
          first=a[i];
          second=b[j];
        }
        
      }
      else
      {
       if(first==a[i])
       {
         i++;
         first=a[i];    
       }
       else
       {
         j++;
         first=b[j];    
       }
     }
     
   }
   ans++;
   cout<<ans<<endl;
 }