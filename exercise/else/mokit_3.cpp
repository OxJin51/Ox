//
// Created by 我的名字是Ox on 2024/3/29 029.
//
#include<iostream>
#include<vector>
using namespace std;
vector<int>a;
bool flag[2]={true, true};
int main()
{
    int t; cin>>t;
    int cnt_up=0,cnt_down=0;
    while(t--)
    {
        int x; cin>>x;
        a.push_back(x);
    }

    for(int i=0;i<a.size()-1;i++)
    {
        if(a[i+1]>a[i]&&!flag[1])
        {   cnt_up++;
            flag[1]=true;
            flag[0]= false;
        }
        else if(a[i+1]<a[i]&&!flag[2])
             {   cnt_down++;
                 flag[0]=true;
                 flag[1]= false;
             }
        else continue;
    }

    if(cnt_down==0&&cnt_up==0)
         printf("0 0");
    else printf("%d %d",cnt_up,cnt_down);
    return 0;
}