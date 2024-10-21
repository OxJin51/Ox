#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    string str;

    //cin>>str;

   getline(cin,str);

    for(auto x:str)
    {
        cout<<x;
    }
    return 0;
}