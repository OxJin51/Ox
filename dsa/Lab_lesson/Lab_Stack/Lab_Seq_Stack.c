//
// Created by 我的名字是Ox on 2024/5/8 008.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 20    /* 顺序栈中最大元素个数，应根据需要定义 */

typedef int ElemType;   /* 顺序栈中元素类型，应根据需要定义，暂定为整型 */

typedef struct SeqStack
{	  /* 顺序栈类型定义 */
    ElemType  elem[MAXSIZE];
    int  top; 	//栈顶位置指示器top，整型
}SeqStack;

/* 顺序栈初始化，置空栈 */
SeqStack *Init_SeqStack()
{
    SeqStack *s=(SeqStack *) malloc(sizeof (SeqStack));  //申请分配顺序栈空间
    if (s==NULL)
        printf("Out of space!! \n");
    else
        s->top=-1;  //初始化栈顶位置为-1
    return s;
}

/* 判断s指向的顺序栈是否为空栈 */
int isEmpty_SeqStack(SeqStack *s)
{
    if(s->top==-1)
        return TRUE;
    else return FALSE;
}

/* 入栈操作：在栈顶位置压入元素x */
int Push_SeqStack(SeqStack *s, ElemType x )
{
    if(s->top==MAXSIZE-1)    //栈满不能入栈
    {printf( "Overflow!  元素%d入栈失败，栈满上溢！\n",x );
        return FALSE;}
    else
    {
        s->top++;   //栈顶位置指示器上移
        s->elem[s->top] = x;   //将x写入栈顶所在的数组元素
        //printf( "元素%d入栈成功！\n",x );
        return TRUE;
    }
}

/* 出栈操作：删除栈顶元素 */
int  Pop_SeqStack (SeqStack *s, ElemType *x)
{
    if (s->top==-1)   //栈空不能出栈
    {printf( "Underflow!  出栈失败，栈空下溢！\n",x );
        return FALSE;}
    else
    { *x=s->elem[s->top];  //栈顶元素位置写入*x
        //printf( "栈顶元素%d出栈成功！\n",*x );
        s->top--;  //栈顶位置指示器下移
        return TRUE;}
}

void  Traverse_SeqStack (SeqStack *s)
{
    int i;
    if(!isEmpty_SeqStack(s))
    {
        printf("顺序栈长度为%d，栈顶位置top=%d，栈顶元素=%d\n",s->top+1,s->top, s->elem[s->top]);
        printf("栈中元素: ");
        for(i=0;i<=s->top;i++)  //从栈底向栈顶依次输出
            printf("%d ", s->elem[i]);
        printf( "<--栈顶\n" );
    }
    else
        printf("顺序栈为空栈！长度为0！");
}

int main()
{
    SeqStack *ps;
    int n,m,v,i=1,j=1;
    char choice=0,ch;

    printf("\n");
    while(choice!='Q' && choice!='q')                //当choice的值不为q且不为Q时循环
    {
        printf("       ********************* 顺 序 栈 常 用 算 法 *********************\n");
        printf("            I.Init    E.Push    P.Pop    T.Traverse    Q.Exit\n");
        if(j==1) {printf("\n注意：请先执行I(Init)一次\n");  j++;}
        printf("请输入您要操作的步骤：");
        scanf("%c",&choice);
        while(choice=='\n') scanf("%c",&choice);
        if(choice=='I'||choice=='i')               //初始化顺序栈
        {ps=(Init_SeqStack());
            printf("顺序栈初始化成功……\n");}
        else if(choice=='E'||choice=='e') {
            printf("请输入要入栈的元素个数:");
            printf("N=");
            scanf("%d",&n);
            printf("请输入要入栈的元素:") ;
            for(i=1;i<=n;i++)
            {
                scanf("%d",&m);
                if(ps->top!=MAXSIZE-1){
                    if (i==1)
                        printf("数据元素") ;
                    if (n==1)
                    { Push_SeqStack(ps, m);
                        printf("%d入栈成功\n",m) ;
                        break;}
                    if(i<n && ps->top!=MAXSIZE-2 )
                    { Push_SeqStack(ps, m);
                        printf("%d,",m) ;}
                    else
                    { Push_SeqStack(ps, m);
                        printf("%d依次入栈成功\n",m) ;}
                }
                else Push_SeqStack(ps, m);
            }		while((ch = getchar()) != '\n' && ch != EOF);
            Traverse_SeqStack (ps);
        }
        else if(choice=='P'||choice=='p'){
            printf("请输入要出栈的元素个数:");
            printf("N=");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                if(!isEmpty_SeqStack(ps))
                { if (i==1)
                        printf("数据元素") ;
                    if (n==1 )
                    { Pop_SeqStack(ps,&v) ;
                        printf("%d出栈成功\n",v) ; break;}
                    if(i<n && ps->top+1>1)
                    { Pop_SeqStack(ps,&v) ;
                        printf("%d,",v) ;}
                    else
                    { Pop_SeqStack(ps,&v) ;
                        printf("%d依次出栈成功\n",v) ;}
                }
                else Pop_SeqStack(ps,&v) ;
            }
            while((ch = getchar()) != '\n' && ch != EOF);
            Traverse_SeqStack (ps);
        }
        else if(choice=='T'||choice=='t')
            Traverse_SeqStack (ps);
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
