//
// Created by 我的名字是Ox on 2024/5/20 020.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
void Reflection (string r, vector<char>&re)
{
    int len = re.size();
    for (int i = 0; i < len; ++i)
    {
        re[r[i] - 'a'] = r[len - 1 - i];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        vector<char> re;
      int n; cin>>n;
      string s;
      cin>>s;
        Reflection(s,re);
      if(n==1) cout<<s;
        for (int i = 0; i < s.size(); ++i)
        {
            s[i] =re[s[i] - 'a'];
        }

      reverse(s.begin(), s.end());


    }
    return 0;
}