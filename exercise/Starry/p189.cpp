//
// Created by 我的名字是Ox on 2024/9/29 029.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int T; cin>>T; //时间个数n
        vector<int>Ballon;
        while(T--)
        {
            int op; cin>>op; //事件类型
            if(op==1)
            {
                int x; cin>>x; //输入气球大小
                Ballon.push_back(x);
            }

            else if(op==2)
            {
                int x; cin>>x; //输入气球大小
                for(vector<int>::iterator it=Ballon.begin();it!=Ballon.end();it++)
                {
                    if(*it==x)
                    {
                        Ballon.erase(it);
                        break;
                    }
                }
            }

            else if(op==3)
            {
                if(!Ballon.empty())
                {
                    vector<int>::iterator maxpo = max_element(Ballon.begin(),Ballon.end());
                    cout<<*maxpo<<endl;
                }
                else cout<<"No Balloon!";

            }

        }
    }
    return 0;
}