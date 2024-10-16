//
// Created by 我的名字是Ox on 2024/5/8 008.
//
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int DataType;     /* 链栈中元素类型，应根据需要定义，暂定为整型 */

typedef struct  node  /* 链栈结点结构 */
{
    DataType data;
    struct  node  *next;
}LinkStack;

/*申请链栈结构空间，创建一空链栈，返回指向空链栈的指针*/
LinkStack  *Init_LinkStack( )
{
    LinkStack *top;
    top =(LinkStack *) malloc(sizeof (LinkStack));  //为头结点分配内存
    if (top!= NULL)
    {top->next=NULL;}   //将头结点的指针域置空
    else
        printf("Out of space! \n");
    return top;
}
/*判断空栈*/
int  isEmpty_LinkStack (LinkStack *top)
{
    return (top==NULL);
}

/* 入栈操作：在栈顶位置压入元素x */
void Push_LinkStack ( LinkStack *top, DataType x )
{
    LinkStack  *p;
    p =(LinkStack *) malloc(sizeof (LinkStack));  //为P结点分配内存
    if ( p == NULL  )
        printf("Out of space!\n");
    else  /* 头插法在头结点之后压入一元素x */
    {
        p->data=x;    //将x写入p结点的数据域
        p->next=top->next;  //p结点的后继结点是头结点的后继结点
        top->next=p;  //头结点的后继结点是p结点
    }
}

/* 出栈操作：删除栈顶元素 */
int  Pop_LinkStack (LinkStack *top, DataType *x) {
    if(isEmpty_LinkStack (top) )
    {printf( "Underflow!  出栈失败，栈空下溢！\n",x );
        return FALSE;}
    else {
        LinkStack  *p = top->next;  //p指向栈顶元素结点
        *x=p->data;  //读栈顶元素的值
        top->next=p->next;  //头结点的后继结点是p结点的后继结点
        free(p);   //释放p结点
        return TRUE;
    }
}

int Length_LinkStack (LinkStack *top)   /*求链栈长度*/
{
    LinkStack *p=top;   //p指向头结点
    int j=0;   //结点计数器j归零
    while (p->next!=NULL)   //当p结点的后继结点存在
    {
        j++;   //计数器+1
        p=p->next;   //指针后移
    }
    return j;
}
/*遍历栈，从栈顶位置到栈底位置，依次输出栈中元素值*/
void  Traverse_LinkStack (LinkStack *top)
{
    LinkStack *p=top->next;   //p指向栈顶元素结点
    if(!isEmpty_LinkStack(top))
    {
        printf("链栈长度为%d，栈顶元素a%d=%d\n", Length_LinkStack(top), Length_LinkStack(top),p->data);
        printf("链栈状态: ");
        printf("top-->头结点");
        while(p!=NULL)   //当p结点存在
        {
            printf("-->%d",p->data);  //输出p结点的值
            p=p->next;   //指针后移
        }
    }
    else
        printf("链栈为空栈！长度为0！");
}

int main()
{
    LinkStack *ps;
    int n,m,v,i=1,j=1;
    char choice,ch;
    printf("\n");
    while(choice!='Q' && choice!='q')                //当choice的值不为q且不为Q时循环
    {
        printf("       ********************* 链 栈 常 用 算 法 *********************\n");
        printf("            I.Init    E.Push    P.Pop    T.Traverse    Q.Exit\n");
        if(j==1) {printf("\n注意：请先执行I(Init)一次\n");  j++;}
        printf("请输入您要操作的步骤：");
        scanf("%c",&choice);
        while((ch = getchar()) != '\n' && ch != EOF);
        if(choice=='I'||choice=='i')               //初始化链栈
        { ps=Init_LinkStack();
            printf("链栈初始化成功……\n"); }
        else if(choice=='E'||choice=='e') {
            printf("请输入要入栈的元素个数:");
            printf("N=");
            scanf("%d",&n);
            printf("请输入要入栈的元素:") ;
            for(i=1;i<=n;i++)
            {	scanf("%d",&m);
                if (i==1)
                    printf("数据元素") ;
                if (n==1)
                { Push_LinkStack(ps, m);
                    printf("%d入栈成功\n",m) ;
                    break;}
                if(i<n)
                {Push_LinkStack(ps, m);
                    printf("%d,",m) ;}
                else
                { Push_LinkStack(ps, m);
                    printf("%d依次入栈成功\n",m) ;
                }

            }
            while((ch = getchar()) != '\n' && ch != EOF);  //
            Traverse_LinkStack (ps);
        }
        else if(choice=='P'||choice=='p'){
            printf("请输入要出栈的元素个数:");
            printf("N=");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                if(!isEmpty_LinkStack(ps))
                { if (i==1)
                        printf("数据元素") ;
                    if (n==1 )
                    { Pop_LinkStack (ps,&v);
                        printf("%d出栈成功\n",v) ; break;}
                    if(i<n && Length_LinkStack(ps)>1)
                    { Pop_LinkStack (ps,&v);
                        printf("%d,",v) ;}
                    else if(i==n || Length_LinkStack(ps)==1)
                    { Pop_LinkStack (ps,&v);
                        printf("%d依次出栈成功\n",v) ;
                    }}
                else Pop_LinkStack (ps,&v);
            }
            while((ch = getchar()) != '\n' && ch != EOF);  //
            Traverse_LinkStack (ps);
        }
        else if(choice=='T'||choice=='t')
            Traverse_LinkStack (ps);
        else if(choice=='Q'||choice=='q')            //退出程序
        {
            exit(0);
        }
        else               //如果选了选项之外的就让用户重新选择
        {
            printf("您没有输入正确的操作指令，请重新输入！\n");
        }
        printf("\n\n");
    }
    return 0;
}