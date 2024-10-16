//
// Created by 我的名字是Ox on 2024/4/15 015.
//
#include<iostream>
#include<cstdlib>
#define MAXSIZE 114514
using namespace std;
struct Stack
{
    int elem[MAXSIZE];
    int top; //总元素=top+1
};
typedef struct Stack * SqStack;
//链式栈
typedef struct node
{
    int data;
    struct node *next;
}Snode,LinkStack;
/*顺序栈的操作*/
/*①初始化顺序栈*/
struct stack * Init_SqStack()
{
    SqStack *s;
    s= (S  )SqStack
    return s;
}
int main()
{

    return 0;
}