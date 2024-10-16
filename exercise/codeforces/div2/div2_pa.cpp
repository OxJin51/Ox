//
// Created by 我的名字是Ox on 2024/3/22 022.
//
#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
const int N=1e5+10;
long int q[N];
int n,cnt;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) scanf("%ld",&q[i]);

        if (n == 1) cout << '1' << endl;

        else
        {
            sort(q, q + n+1);

            int mid_num = q[n>>1]; //求中位数

            int l = 0, r = n - 1;

            while (l < r) {
                int mid = l + r >> 1;
                if (q[mid] < mid_num) l = mid;
                else r = mid - 1;
            }

            cnt = abs(q[l] - mid_num);

            cout << cnt;

            puts("");
        }
    }
    return 0;
}