//
// Created by 我的名字是Ox on 2024/3/22 022.
//
#include<iostream>
#define MAXSIZE 100
using namespace std;
struct list
{
    int elem[MAXSIZE];
    int length;
};
typedef struct list Sqlist; //给struct list起个别名Sqlist


int SumIf_Seqlist(Sqlist *L,int x)
{
    int sum=0;
   for (int i=0;i<L->length;i++)
   {
       if(L->elem[i]<x) sum+=L->elem[i];
   }
   return sum;
}


int main()
{
    Sqlist l;
    cout<<"enter the length"<<endl;
    cin>>l.length;
    for(int i=0;i<l.length;i++) cin>>l.elem[i];
    printf("%d",SumIf_Seqlist(&l,3));
    return 0;
}
