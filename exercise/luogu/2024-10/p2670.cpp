//
// Created by 我的名字是Ox on 2024/10/21 021.
//
#include<iostream>
#include<cstring>
using namespace std;
const int N = 130;
bool q[N][N];
int boom[N][N];
int n,m;
int dx[8]={1,0,-1,0,-1,1,1,-1};
int dy[8]={0,1,0,-1,-1,-1,1,1};
void solve(int x,int y)
{
    int nx,ny;
    for(int k=0;k<8;k++)
    {
        nx=x+dx[k];
        ny=y+dy[k];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
            boom[nx][ny]++;
    }
}
int main()
{
    cin>>n>>m;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string str;
        getline(cin,str); //读取第i行

        for (int j = 1; j <= m; j++)
        {
            if (str[j - 1] == '*')
            {
                q[i][j] = true; // 有地雷
                solve(i,j);
            }
            else
            {
                q[i][j] = false; // 没有地雷
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (q[i][j]) cout << '*'; // 输出地雷
            else cout << boom[i][j]; // 输出周围的地雷数
        }
        cout<<endl;
    }





    return 0;
}