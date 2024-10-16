//
// Created by 我的名字是Ox on 2024/10/16 016.
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
    int t=3,n; //铅笔个数
    vector<long long int>cost;
    cin>>n;
    while(t--)
    {

        int num, price,dx=1;
        cin >> num >> price;
        if(n%num == 0) dx=0;
        long long int  total = (n / num + dx) * price;
        cost.push_back(total);
    }

    /*for (vector<long long int >::iterator it = cost.begin(); it != cost.end(); ++it)
    {
        cout << *it << " ";
    }*/

    //cout<<"result"<<endl;
    cout<<*min_element(cost.begin(), cost.end());
    return 0;
}