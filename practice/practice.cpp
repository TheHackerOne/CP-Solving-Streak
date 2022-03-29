//difficult question.......
#include <iostream>
#include<string>
using namespace std;

bool helper(string str)
{
    cout<<str<<endl;
   if(str.size()==1)//base case...
   {
       return 1;
   }
   //below conditions are thought if here are atleast 3 characters....
    if(str[1]=='a')//1 jump ki condition......allowed for both s[0]=a or s[0]=b.....
    {
        return helper(str.substr(1)); 
    }
    else if(str[0]=='a' && str[1]=='b' && str[2]=='b')//2 jump ki condition...allowed only for s[0]=a
    {        
        return helper(str.substr(2)); 
    }
    return 0;
}
bool check(string str)
{
    if(str.size()==0)//empty string...
    {
       return 0; 
    }
    //yahan aane ka matlab string kam se kam 1size  ki hai....
    if(str[0]=='a')
    {
        return helper(str);
    }
    return 0;
}
int main()
{
    string str;
    cin>>str;
    if(check(str))
    cout<<"true";
    else 
    cout<<"false";
}

https://memoria-io.herokuapp.com