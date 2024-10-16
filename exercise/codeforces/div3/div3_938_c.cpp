//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
vector<int>a;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        a.clear();
        //输入
        int n,k; cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int x; cin>>x; a.push_back(x);
        }

        int cnt = 0;
        int attacks = 0;
        int left = 0, right = n - 1;

        while (attacks < k && left <= right)
        {
            if (a[left] == 0)
            {
              //  cnt++;
                left++;
            }
            else
            {
                a[left]--;
                attacks++;
                if (attacks == k) break;
                if (a[left] == 0) cnt++;
            }



            if (a[right] == 0)
            {
                //cnt++;
                right--;
            }
            else
            {a[right]--;
            attacks++;
                if (attacks == k) break;


                if (a[left] == 0) cnt++;
            }


        }


        cout<<cnt<<endl;

    }
    return 0;
}