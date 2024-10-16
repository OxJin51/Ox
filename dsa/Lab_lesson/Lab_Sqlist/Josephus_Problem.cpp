//
// Created by 我的名字是Ox on 2024/4/23 023.
//
#include<iostream>
#include<cstdlib>
#define MAXSIZE 100
using namespace std;
struct list
{
    int elem[MAXSIZE];
    int length;
};
typedef struct list Sqlist; //给struct list起个别名Sqlist

//顺序表的初始化
void Init_Sqlist(struct list *L)
{
    L->length = 0; //顺序表中对象置零
}
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    Sqlist L;
    Init_Sqlist(&L);
    int n; cin>>n;
    L.length=n;
    //输入密码
    for(int i=0;i<n;i++) cin>>L.elem[i];

    


    return 0;
}