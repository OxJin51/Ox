//
// Created by 我的名字是Ox on 2024/2/5 005.
//
#include <iostream>
using namespace  std;
struct Node
{
    int val;
    Node* next;

    // 构造函数
    Node(int _val) : val(_val), next(NULL) {}
};

int main()
{
    Node *p = new Node(1);
    Node *q = new Node(2);
    Node *o = new Node(3);

    p->next = q;
    q->next = o;
    Node *head = p; //p为头节点

    //添加节点
    Node *u = new Node(4);
    u->next = head;
    head = u;

    //删除节点
    head->next = head->next->next;

    //链表遍历
    for(Node *i =head;i;i=i->next)
        cout << i->val <<endl;


    return 0;
}
