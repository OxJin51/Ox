//
// Created by 我的名字是Ox on 2024/2/19 019.
//
#include<iostream>
using namespace std;
char a[110][110];
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    //输入字符矩阵
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    //输入p，q
    int p,q; //p天 每天q次移动
    cin>>p>>q;
    while(p--) //天的循环
    {

        for (int i = 0; i < q; i++) //一天移动q次
      {
          int op,z;
          cin>>op>>z;
          if(op==1) //行循环移动 a[z-1][j];
          {
              char t=a[z-1][m-1];
              for(int j=m-1;j>0;j--)
              {
                  a[z-1][j]=a[z-1][j-1];
              }
              a[z-1][0]=t; //处理开头
          }
          else if(op==2) //列循环移动 a[i][z];
          {
              char t=a[n-1][z-1];
              for(int i=n-1;i>0;i--)
              {
                  a[i][z-1]=a[i-1][z-1];
              }
              a[0][z-1]=t; //处理开头
          }
      }
    }
    cout<<a[x-1][y-1]<<endl;
    return 0;
}