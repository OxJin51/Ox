//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
using namespace std;
int a[10][10];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n; //矩阵n*n
      cin>>n;
      //input
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {
              cin>>a[i][j];
          }
      }
      int cnt[10]={0};
      //遍历
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1) {cnt[i]++;}
            }
        }
        for(int i=0;i<10;i++)
        {
            if(cnt[i]>0)
            {
                if (i + 1 < 10)
                {
                    if (cnt[i] == cnt[i + 1])
                    {
                        cout << "SQUARE" << endl;
                        break;
                    }
                    else //
                    {
                        cout << "TRIANGLE" << endl;
                        break;
                    }

                }
            }
        }

    }
    return 0;
}